from random import shuffle
import time


def monkey_sort(arr):
    time = 0
    while True:
        flag = True
        for i in range(len(arr) - 1):
            if arr[i] > arr[i + 1]:
                flag = False
                break
        if flag:
            break
        time += 1
        print(arr)
        shuffle(arr)
    return arr, time


a = []
for i in range(1,10):
    a.append(i)
a.append(0)
start_time = time.time()
# 执行函数
print(monkey_sort(a))
# 记录结束时间
end_time = time.time()
print("耗时：", end_time - start_time)
