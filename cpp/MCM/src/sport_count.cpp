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

    // 公式 -> (X X^T)^-1 X^T Y
    // 数据 -> 1. 参赛人数 2. 近几年金牌人数
    auto clear_space = [](std::string str) -> std::string {
        size_t pos = str.find(" ");
        return str.substr(pos + 1);
    };
    std::map<std::string, std::map<int, CountryData>> contry_count;
    std::map<std::string, std::map<int, std::map<std::string, CountryData>>> sport_count;
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
            sport_count[noc][year][sport].gold.insert(sport + event);
        } else if (medal == "Silver") {
            contry_count[noc][year].silver.insert(sport + event);
            sport_count[noc][year][sport].silver.insert(sport + event);
        } else if (medal == "Bronze") {
            contry_count[noc][year].bronze.insert(sport + event);
            sport_count[noc][year][sport].bronze.insert(sport + event);
        } else {
            contry_count[noc][year].none++;
            sport_count[noc][year][sport].none++;
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
    std::string output_filename = "D:\\PrecticeContest\\cpp\\MCM\\data\\new_count.csv";
    std::ofstream csvFile(output_filename);
    if (!csvFile.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }
    for (auto [noc, data] : sport_count) {
        // if (noc != "BRA" && noc != "IND" && noc != "RSA") continue;
        for (auto [year, sport_data] : data) {
            // if (year < 2000 || year > 2024) continue;
            for (auto [sport, contry_data] : sport_data) {
                int gold = contry_data.gold.size();
                int silver = contry_data.silver.size();
                int bronze = contry_data.bronze.size();
                int total = gold + silver + bronze;
                int all = total + contry_data.none;
                std::string qwq = sport;
                if (sport.find(",") != std::string::npos) qwq = sport.substr(0, sport.find(","));
                csvFile << noc << "," << year << "," << qwq << "," << gold << "," << silver << "," << bronze << ","
                        << total << "," << all << std::endl;
            }
            // std::vector<std::tuple<std::string, int, int, int>> cnt;
            // for (auto [sport, contry_data] : sport_data) {
            //     int gold = contry_data.gold.size();
            //     int silver = contry_data.silver.size();
            //     int bronze = contry_data.bronze.size();
            //     cnt.push_back({sport, gold, silver, bronze});
            // }

            // std::sort(cnt.begin(), cnt.end(), [](const auto &a, const auto &b) {
            //     if (get<1>(a) != get<1>(b)) return get<1>(a) > get<1>(b);
            //     if (get<2>(a) != get<2>(b)) return get<2>(a) > get<2>(b);
            //     return get<3>(a) > get<3>(b);
            // });
            // csvFile << noc << "," << year << ",";
            // int n = std::min(3, static_cast<int>(cnt.size()));

            // for (int i = 0; i < n; ++i) {
            //     const auto &sport = get<0>(cnt[i]);
            //     const auto &contry_data = sport_data[sport];
            //     int gold = contry_data.gold.size();
            //     int silver = contry_data.silver.size();
            //     int bronze = contry_data.bronze.size();
            //     int total = gold + silver + bronze;
            //     int all = total + contry_data.none;
            //     char c = (i != 2) ? ',' : '\n';
            //     csvFile << sport << "," << gold << "," << silver << "," << bronze << "," << total << "," << all << c;
            // }

            // for (int i = 0; i < 3 - n; ++i) {
            //     char c = (i != (2 - n)) ? ',' : '\n';
            //     csvFile << "NULL,0,0,0,0,0" << c;
            // }
        }
    }

    csvFile.close();
    std::cout << "CSV file written successfully: " << output_filename << std::endl;
    system("pause");
    return 0;
}
