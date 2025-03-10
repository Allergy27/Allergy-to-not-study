import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.preprocessing import StandardScaler


# 数据预处理函数 (保持中文列名处理)
def preprocess_data(filepath):
    """Process long-format data"""
    try:
        df = pd.read_csv(
            filepath,
            header=0,
            names=[
                "Country",
                "Year",
                "Sport",
                "Gold",
                "Silver",
                "Bronze",
                "TotalMedals",
                "Athletes",
            ],
            dtype={
                "Country": "category",
                "Year": "int16",
                "Sport": "category",
                "Gold": "float32",
                "Silver": "float32",
                "Bronze": "float32",
                "Athletes": "float32",
            },
        )

        # 数据清洗保持不变
        df = df[
            (df["Sport"] != "NULL") & (df["Sport"].notna()) & (df["Athletes"] > 0)
        ].copy()

        # 转换运动项目名为标题格式
        df["Sport"] = df["Sport"].astype(str).str.strip().str.title()

        numeric_cols = ["Gold", "Silver", "Bronze", "Athletes"]
        df[numeric_cols] = (
            df[numeric_cols].apply(pd.to_numeric, errors="coerce").fillna(0)
        )

        return df

    except Exception as e:
        print(f"Data loading failed: {str(e)}")
        exit()


# 核心计算函数（保持不变）
def calculate_impact(df):
    current_year = df["Year"].max()
    df["YearWeight"] = np.where(current_year - df["Year"] <= 8, 1.2, 0.8)

    grouped = (
        df.groupby(["Country", "Sport"], observed=False)
        .agg(
            {
                "Gold": lambda x: (x * df.loc[x.index, "YearWeight"]).sum(),
                "Silver": lambda x: (x * df.loc[x.index, "YearWeight"]).sum(),
                "Bronze": lambda x: (x * df.loc[x.index, "YearWeight"]).sum(),
                "Athletes": "sum",
                "Year": ["nunique", "max"],
            }
        )
        .reset_index()
    )

    grouped.columns = [
        "Country",
        "Sport",
        "WeightedGold",
        "WeightedSilver",
        "WeightedBronze",
        "TotalAthletes",
        "AppearanceYears",
        "LastParticipation",
    ]

    grouped["MedalImpact"] = (
        grouped["WeightedGold"] * 3
        + grouped["WeightedSilver"] * 2
        + grouped["WeightedBronze"] * 1
    )
    grouped["ParticipationImpact"] = np.log1p(grouped["TotalAthletes"])
    grouped["RecencyImpact"] = (current_year - grouped["LastParticipation"]).apply(
        lambda x: 1 if x <= 4 else 0.5 if x <= 8 else 0.2
    )

    scaler = StandardScaler()
    features = ["MedalImpact", "ParticipationImpact", "RecencyImpact"]
    grouped[["NormMedal", "NormParticipation", "NormRecency"]] = scaler.fit_transform(
        grouped[features]
    )

    grouped["WeightMedal"] = grouped["AppearanceYears"].apply(
        lambda x: 0.7 if x >= 3 else 0.5
    )
    grouped["WeightParticipation"] = 0.25
    grouped["WeightRecency"] = 0.05

    grouped["ImpactScore"] = (
        grouped["NormMedal"] * grouped["WeightMedal"]
        + grouped["NormParticipation"] * grouped["WeightParticipation"]
        + grouped["NormRecency"] * grouped["WeightRecency"]
    )

    return grouped.sort_values(["Country", "ImpactScore"], ascending=[True, False])


# 英文可视化函数
def visualize_impact(df, country, top_n=3):
    country_df = df[df["Country"] == country].head(top_n)

    if country_df.empty:
        print(f"No data available for {country}")
        return

    # 创建水平柱状图
    plt.figure(figsize=(10, 6))
    bars = plt.barh(
        country_df["Sport"],
        country_df["ImpactScore"],
        color=["#1f77b4", "#ff7f0e", "#2ca02c"],
    )

    plt.title(f"Top {top_n} Strategic Sports for {country}", fontsize=14)
    plt.xlabel("Composite Impact Score", fontsize=12)
    plt.gca().invert_yaxis()

    # 添加数据标签
    for bar in bars:
        width = bar.get_width()
        plt.text(
            width + 0.02,
            bar.get_y() + bar.get_height() / 2,
            f"{width:.2f}",
            va="center",
        )

    plt.tight_layout()
    plt.savefig(f"D:\\PrecticeContest\\cpp\\MCM\\data\\RES\\{country}_sports_impact.png", dpi=300, bbox_inches="tight")
    plt.close()


if __name__ == "__main__":
    data_path = "D:\\PrecticeContest\\cpp\\MCM\\data\\new_count.csv"

    try:
        # 数据处理流程
        df = preprocess_data(data_path)
        impact_df = calculate_impact(df)

        # 输出英文结果
        print("Country Sport Impact Ranking:")
        print(
            impact_df.groupby("Country")
            .head(3)
            .reset_index(drop=True)[
                [
                    "Country",
                    "Sport",
                    "ImpactScore",
                    "WeightedGold",
                    "WeightedSilver",
                    "WeightedBronze",
                    "AppearanceYears",
                    "TotalAthletes",
                ]
            ]
        )

        # 生成英文图表
        for country in impact_df["Country"].unique():
            visualize_impact(impact_df, country)

        # 保存结果
        impact_df.to_csv("D:\\PrecticeContest\\cpp\MCM\\data\\RES\\sports_impact_analysis.csv", index=False)

    except Exception as e:
        print(f"Processing error: {str(e)}")
        exit()
