from PIL import Image
import os
current_directory = os.path.dirname(os.path.abspath(__file__))

def compress_image(input_image_path, output_image_path, target_width, target_height):
    original_image = Image.open(input_image_path)
    # 获取原始图片的尺寸
    original_width, original_height = original_image.size
    # 计算压缩比例
    width_ratio = target_width / original_width
    height_ratio = target_height / original_height
    # 确定使用哪个比例进行压缩，避免图片失真
    ratio = min(width_ratio, height_ratio)
    # 计算新的尺寸
    new_width = int(original_width * ratio)
    new_height = int(original_height * ratio)
    # 压缩图片
    compressed_image = original_image.resize((new_width, new_height), Image.LANCZOS)
    # 保存压缩后的图片
    change_image=compressed_image.convert('L')
    for x in range(change_image.width):
        for y in range(change_image.height):
            grey=change_image.getpixel((x, y))
            if grey<140:grey=0
            change_image.putpixel((x,y),grey)
    change_image.save(output_image_path)

input_path = current_directory+'\\1.png'  # 原始图片路径
output_path = current_directory+'\\2.png'  # 压缩后图片保存路径
target_width = 28  # 目标宽度
target_height = 28  # 目标高度
compress_image(input_path, output_path, target_width, target_height)