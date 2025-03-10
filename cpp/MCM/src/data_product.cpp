// Copyright MCM 2025
#include "../include/Eigen/Dense"
#include "../include/csv.hpp"
#include "../include/head.hpp"

const int N = 3;  // 参数

struct CountryData {  // 国家某年数据
    std::set<std::string> gold;
    std::set<std::string> silver;
    std::set<std::string> bronze;
    int none;
};

struct ProgramData {  // 各年项目数据
    int total_events;
    int total_disciplines;
    int total_sports;
};

int main() {
    std::map<int, std::string> host_nations = {
        {1896, "GRE"}, {1900, "FRA"}, {1904, "USA"}, {1908, "GBR"}, {1912, "SWE"}, {1920, "BEL"}, {1924, "FRA"},
        {1932, "USA"}, {1936, "GER"}, {1948, "GBR"}, {1956, "AUS"}, {1960, "ITA"}, {1964, "JPN"}, {1968, "MEX"},
        {1972, "FRG"}, {1976, "CAN"}, {1980, "URS"}, {1988, "KOR"}, {1992, "ESP"}, {1996, "USA"}, {2000, "AUS"},
        {2004, "GRE"}, {2008, "CHN"}, {2012, "GBR"}, {2016, "BRA"}, {2020, "JPN"}, {2024, "FRA"}, {2028, "USA"}};

    // 路径

    std::string filename = "D:\\PrecticeContest\\cpp\\MCM\\data\\summerOly_athletes.csv";
    csv::CSVReader ath_reader(filename);
    filename = "D:\\PrecticeContest\\cpp\\MCM\\data\\summerOly_programs.csv";
    csv::CSVReader pro_reader(filename);

    // 公式 -> (X X^T)^-1 X^T Y
    // 数据 -> 1. 参赛人数 2. 近几年金牌人数
    auto clear_space = [](std::string str) -> std::string {
        size_t pos = str.find(" ");
        return str.substr(pos + 1);
    };
    std::map<std::string, std::map<int, CountryData>> contry_count;
    std::map<int, ProgramData> pro_all;
    for (auto &row : ath_reader) {
        int year = stoi(clear_space(row["Year"]));
        // if (year < 1996) continue;
        std::string noc = clear_space(row["NOC"]);
        std::string sport = clear_space(row["Sport"]);
        std::string event = clear_space(row["Event"]);
        std::string medal = clear_space(row["Medal"]);
        if (medal == "Gold") {
            contry_count[noc][year].gold.insert(sport + event);
        } else if (medal == "Silver") {
            contry_count[noc][year].silver.insert(sport + event);
        } else if (medal == "Bronze") {
            contry_count[noc][year].bronze.insert(sport + event);
        } else {
            contry_count[noc][year].none++;
        }
    }
    int row_count = 0;
    std::map<int, int> new_pro;  // 新项目

    auto trans = [](std::string str) -> int {
        if (str.size() == 0) return 0;
        for (auto c : str) {
            if (c < '0' || c > '9') return 0;
        }
        return stoi(str);
    };

    for (auto &row : pro_reader) {
        if (row_count < 71) {
            for (int col = 4; col < row.size(); ++col) {
                int year = stoi(clear_space(pro_reader.get_col_names()[col]));
                // if (year < 1996) continue;
                int new_num = trans(clear_space(row[col]));
                int old_num = trans(clear_space(row[col - 1]));
                if (new_num > old_num) new_pro[year] += new_num - old_num;
            }
        } else if (row_count == 71) {
            for (int col = 4; col < row.size(); ++col) {
                int year = stoi(clear_space(pro_reader.get_col_names()[col]));
                // if (year < 1996) continue;
                pro_all[year].total_events += stoi(clear_space(row[col]));
            }
        } else if (row_count == 72) {
            for (int col = 4; col < row.size(); ++col) {
                int year = stoi(clear_space(pro_reader.get_col_names()[col]));
                // if (year < 1996) continue;
                pro_all[year].total_disciplines += stoi(clear_space(row[col]));
            }
        } else if (row_count == 73) {
            for (int col = 4; col < row.size(); ++col) {
                int year = stoi(clear_space(pro_reader.get_col_names()[col]));
                // if (year < 1996) continue;
                pro_all[year].total_sports += stoi(clear_space(row[col]));
            }
        }
        row_count++;
    }
    std::string output_filename = "D:\\PrecticeContest\\cpp\\MCM\\data\\fade_country_over1996.csv";
    std::ofstream csvFile(output_filename);
    if (!csvFile.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }
    std::map<std::string, int> year_sum;  // 参加次数的前缀和 -> 对年的累计
    std::set<std::string> new_get;        // 拿过奖的国家
    for (auto [country, data] : contry_count) {
        /*
        // 寻找没拿过奖的小国
        int f = 0;
        for (auto [year, contry_data] : data) {
            // if (year < 1996) continue;
            int gold = contry_data.gold.size();
            int silver = contry_data.silver.size();
            int bronze = contry_data.bronze.size();
            int total = gold + silver + bronze;
            if (total > 0) {
                f = 1;
                break;
            }
        }
        if (f != 0) continue;
        */
        for (auto [year, contry_data] : data) {
            // if (year < 1996) continue;
            int gold = contry_data.gold.size();
            int silver = contry_data.silver.size();
            int bronze = contry_data.bronze.size();
            int total = gold + silver + bronze;
            // if (total != 0) continue;
            int total_num = total + contry_data.none;
            int g = 0;
            if (new_get.find(country) == new_get.end() && total > 0) {
                new_get.insert(country);
                g = 1;
            }
            int host = (host_nations[year] == country);
            csvFile << country << "," << year << "," << gold << "," << silver << "," << bronze << "," << total << ","
                    << total_num << "," << ++year_sum[country] << "," << pro_all[year].total_events << ","
                    << new_pro[year] << "," << g << std::endl;
        }
    }
    csvFile.close();
    std::cout << "CSV file written successfully: " << output_filename << std::endl;
    system("pause");
    return 0;
}
