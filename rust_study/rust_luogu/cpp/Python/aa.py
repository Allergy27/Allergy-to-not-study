import os
import zipfile

def unzip_recursive(zip_path, extract_folder):
    """
    递归解压zip文件，直到解压出txt文件
    :param zip_path: 当前zip文件路径
    :param extract_folder: 解压文件的输出文件夹
    :return: None
    """
    # 打开当前的zip文件
    with zipfile.ZipFile(zip_path, 'r') as zip_ref:
        # 解压到指定文件夹
        zip_ref.extractall(extract_folder)

        # 遍历解压后的文件，检查是否有其他zip文件
        for root, dirs, files in os.walk(extract_folder):
            for file in files:
                file_path = os.path.join(root, file)
                if file.endswith('.zip'):
                    # 如果解压出来的文件是zip文件，递归调用
                    new_extract_folder = os.path.splitext(file_path)[0]  # 为下层创建新的解压目录
                    os.makedirs(new_extract_folder, exist_ok=True)
                    unzip_recursive(file_path, new_extract_folder)

def merge_txt_files(extract_folder, output_txt_file):
    """
    合并解压文件夹中的所有txt文件到一个输出文件
    :param extract_folder: 解压后的文件夹路径
    :param output_txt_file: 合并的txt输出文件路径
    :return: None
    """
    with open(output_txt_file, 'w', encoding='utf-8') as output_file:
        # 遍历解压文件夹中的所有文件
        for root, dirs, files in os.walk(extract_folder):
            for file in files:
                if file.endswith('.txt'):
                    txt_file_path = os.path.join(root, file)
                    # 读取txt文件内容并写入输出文件
                    with open(txt_file_path, 'r', encoding='utf-8') as txt_file:
                        content = txt_file.read()
                        output_file.write(content + "\n")

    print(f"所有txt文件内容已合并到 {output_txt_file}")

# 使用示例
def unzip_and_merge_all_txt(zip_path, output_txt_file):
    extract_folder = "unzipped_files"
    os.makedirs(extract_folder, exist_ok=True)

    # 递归解压
    unzip_recursive(zip_path, extract_folder)

    # 合并所有txt文件
    merge_txt_files(extract_folder, output_txt_file)

# 示例
zip_path = 'C:/Users/Allergy/Downloads/tutorial-signin.zip'  # 替换为你的zip文件路径
output_txt_file = 'merged_output.txt'  # 输出文件路径
unzip_and_merge_all_txt(zip_path, output_txt_file)