import torch
from torch.utils.data import DataLoader
from torchvision import transforms
from torchvision.datasets import MNIST #手写数字数据集
import matplotlib.pyplot as plt
from PIL import Image
import os

current_directory = os.path.dirname(os.path.abspath(__file__))

class Net(torch.nn.Module): #主体

    def __init__(self):
        super().__init__()
        self.fc1 = torch.nn.Linear(28*28, 64) #28*28的图像
        self.fc2 = torch.nn.Linear(64, 64)
        self.fc3 = torch.nn.Linear(64, 64)
        self.fc4 = torch.nn.Linear(64, 10) #10层输出10种数字

    def forward(self, x):
        x = torch.nn.functional.relu(self.fc1(x))#先做线性运算再套上激活函数
        x = torch.nn.functional.relu(self.fc2(x))
        x = torch.nn.functional.relu(self.fc3(x))
        x = torch.nn.functional.log_softmax(self.fc4(x), dim=1)#softmax归一化
        return x

def get_data_loader(is_train): #联网下载数据集
    to_tensor = transforms.Compose([transforms.ToTensor()])
    data_set = MNIST("", is_train, transform=to_tensor, download=True)
    return DataLoader(data_set, batch_size=15, shuffle=True)

def evaluate(test_data, net):#评估神经网络的正确率
    n_correct = 0
    n_total = 0
    with torch.no_grad():
        for (x, y) in test_data:
            outputs = net.forward(x.view(-1, 28*28))
            for i, output in enumerate(outputs):
                if torch.argmax(output) == y[i]:
                    n_correct += 1
                n_total += 1
    return round(n_correct / n_total,4)*100

def main():
    train_data = get_data_loader(is_train=True)
    test_data = get_data_loader(is_train=False)
    image = Image.open(current_directory+"\\2.png")
    transform = transforms.Compose([transforms.ToTensor()])
    check_image = transform(image)

    net = Net()
    print("训练前正确率:", evaluate(test_data, net),"%", sep='')
    optimizer = torch.optim.Adam(net.parameters(), lr=0.001)
    for epoch in range(1):#训练轮次
        for (x, y) in train_data:
            net.zero_grad()
            output = net.forward(x.view(-1, 28*28))
            loss = torch.nn.functional.nll_loss(output, y)
            loss.backward()
            optimizer.step()
        print("第", epoch + 1, "轮正确率:", evaluate(test_data, net),"%" , sep='')

    predict = torch.argmax(net.forward(check_image[0].view(-1, 28*28)))
    plt.figure(1)
    plt.imshow(check_image[0].view(28, 28))
    plt.title("prediction: " + str(int(predict)))
    plt.show()
    for (n, (x, _)) in enumerate(test_data):#抽取图像并打印正确率
        if n >=3:break #抽取三张图片
        predict = torch.argmax(net.forward(x[0].view(-1, 28*28)))
        #下面是打印
        plt.figure(n)
        plt.imshow(x[0].view(28, 28))
        plt.title("prediction: " + str(int(predict)))
    plt.show()

if __name__ == "__main__":
    main()