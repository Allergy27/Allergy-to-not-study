// Copyright MCM 2025
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

    // std::cout << "Please input the path (folder): ";
    std::string path = "D:\\PrecticeContest\\cpp\\MCM\\data\\";
    std::string filename = path + "summerOly_athletes.csv";
    csv::CSVReader ath_reader(filename);

    // 公式 -> (X X^T)^-1 X^T Y
    // 数据 -> 1. 参赛人数 2. 近几年金牌人数
    auto clear_space = [](std::string str) -> std::string {
        size_t pos = str.find(" ");
        return str.substr(pos + 1);
    };
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
            sport_count[noc][year][sport].gold.insert(sport + event);
        } else if (medal == "Silver") {
            sport_count[noc][year][sport].silver.insert(sport + event);
        } else if (medal == "Bronze") {
            sport_count[noc][year][sport].bronze.insert(sport + event);
        } else {
            sport_count[noc][year][sport].none++;
        }
    }
    int row_count = 0;

    auto print = [&](std::string aim_sport, std::string noc1, std::string noc2, int year_l, int year_r) -> void {
        std::string output_filename = path + "COMPARE\\" + noc1 + "_" + noc2 + "_" + std::to_string(year_l) + "_" +
                                      std::to_string(year_r) + ".csv";
        std::ofstream csvFile(output_filename);
        if (!csvFile.is_open()) {
            std::cout << "Error opening file" << std::endl;
            return;
        }
        for (auto [noc, data] : sport_count) {  // 遍历国家
            if (noc != noc1 && noc != noc2) continue;
            for (auto [year, sport_data] : data) {
                if (year < year_l || year > year_r) continue;
                csvFile << noc << "," << year << ",";
                for (auto [sport, contry_data] : sport_data) {
                    if (sport != aim_sport) continue;
                    int gold = contry_data.gold.size();
                    int silver = contry_data.silver.size();
                    int bronze = contry_data.bronze.size();
                    int total = gold + silver + bronze;
                    csvFile << sport << "," << gold << "," << silver << "," << bronze << "," << total << std::endl;
                }
            }
        }

        csvFile.close();
        std::cout << "CSV file written successfully: " << output_filename << std::endl;
    };

    print("Swimming", "AUS", "RUS", 1996, 2004);
    print("Synchronized Swimming", "CHN", "RUS", 1996, 2012);
    print("Fencing", "FRA", "RUS", 1988, 2004);
    print("Diving", "CAN", "RUS", 1988, 2000);
    print("Rowing", "USA", "NZL", 1996, 2012);

    system("pause");
    return 0;
}
