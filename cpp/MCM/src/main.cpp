// Copyright MCM 2025
#include "../include/Eigen/Dense"
#include "../include/csv.hpp"
#include "../include/head.hpp"

const int N = 3;  // 参数

int main() {
    std::map<int, std::string> host_nations = {
        {1896, "GRE"}, {1900, "FRA"}, {1904, "USA"}, {1908, "GBR"}, {1912, "SWE"}, {1920, "BEL"}, {1924, "FRA"},
        {1932, "USA"}, {1936, "GER"}, {1948, "GBR"}, {1956, "AUS"}, {1960, "ITA"}, {1964, "JPN"}, {1968, "MEX"},
        {1972, "FRG"}, {1976, "CAN"}, {1980, "URS"}, {1988, "KOR"}, {1992, "ESP"}, {1996, "USA"}, {2000, "AUS"},
        {2004, "GRE"}, {2008, "CHN"}, {2012, "GBR"}, {2016, "BRA"}, {2020, "JPN"}, {2024, "FRA"}, {2028, "USA"}};

    // 路径
    std::string filename = "D:\\PrecticeContest\\cpp\\MCM\\data\\summerOly_athletes.csv";
    csv::CSVReader ath_reader(filename);
    std::map<std::string, std::map<std::string, int>> year_count;
    std::map<std::string, std::map<std::string, std::set<std::string>>> noc_count;
    std::map<std::string, std::map<std::string, std::map<std::string, int>>> pro_count;  // 该国家该年份该项目金牌数
    // 公式 -> (X X^T)^-1 X^T Y
    // 数据 -> 1. 参赛人数 2. 近几年金牌人数
    auto clear_space = [](std::string str) -> std::string {
        size_t pos = str.find(" ");
        return str.substr(pos + 1);
    };

    for (auto& row : ath_reader) {
        std::string year = clear_space(row["Year"]);
        if (stoi(year) < 1996) continue;
        std::string noc = clear_space(row["NOC"]);
        std::string sport = clear_space(row["Sport"]);
        std::string event = clear_space(row["Event"]);
        // pro_count[noc][year][sport]++;
        year_count[year][noc]++;
        if (row["Medal"] == "Gold") noc_count[noc][year].insert(sport + event);
    }

    //  每年各国参赛人数 -> year_count[year][noc]
    //  各国各年金牌人数 -> noc_count[noc][year]
    std::map<std::string, Eigen::MatrixXd> Beta;

    for (auto& [noc, inner_map] : noc_count) {
        // 该国家的金牌预测数
        int n = inner_map.size();
        Eigen::MatrixXd X(n, N);
        Eigen::VectorXd Y(n);
        int i = 0;
        for (auto& [key, value] : inner_map) {
            X(i, 0) = 1;
            X(i, 1) = host_nations[stoi(clear_space(key))] == noc;     // 该年份是否为主办国
            X(i, 2) = year_count[std::to_string(stoi(key) - 4)][noc];  // 该年份参赛人数
            Y(i) = static_cast<double>(value.size());
            i++;
        }
        Beta[noc] = (X.transpose() * X).ldlt().solve(X.transpose() * Y);
    }

    auto calc = [&](std::string noc, int year) -> int {
        Eigen::VectorXd X(N);
        X << 1, (host_nations[year] == noc), year_count[std::to_string(year - 4)][noc];
        return round((X.transpose() * Beta[noc])(0));
    };

    int all = 0;
    double all_rate = 0;

    for (auto& [noc, inner_map] : noc_count) {
        std::cout << noc << ':' << std::endl;
        for (auto& [year, value] : inner_map) {
            if (stoi(year) < 2000) continue;
            int a = calc(noc, stoi(year)), b = value.size();
            double c = abs(a - b) * 1.0 / (b * 1.0) * 100;
            std::cout << year << ' ' << a << ' ' << b << ' ' << abs(a - b) << ' ' << c << std::endl;
            ++all;
            all_rate += c;
        }
    }

    std::cout << "China : " << calc("CHN", 2028) << std::endl;
    std::cout << "all_rate: " << all_rate / all << std::endl;

    system("pause");
    return 0;
}

void cout_year(std::map<std::string, std::map<std::string, std::set<std::string>>> noc_count) {
    //  各国各年金牌人
    for (auto& [key, inner_map] : noc_count) {
        std::cout << key << ":\n";
        for (auto& [key, value] : inner_map) std::cout << key << " " << value.size() << std::endl;
        std::cout << std::endl;
    }
}

void cout_man(std::map<std::string, std::map<std::string, int>> year_count) {
    //  每年各国参赛人数
    for (auto& [key, inner_map] : year_count) {
        std::cout << key << ":\n";
        for (auto& [key, value] : inner_map) std::cout << key << " " << value << std::endl;
        std::cout << std::endl;
    }
}
