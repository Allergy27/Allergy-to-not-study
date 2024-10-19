import matplotlib.pyplot as plt
import numpy as np

PITY = 80

f = np.zeros(PITY)
result = np.zeros(PITY + 1)
single_rate = [0.008] * (PITY + 1)
for i in range(74, 81):
  single_rate[i] = min((1.0, single_rate[i - 1] + 0.08))

### Calculate
f[0] = 1
for i in range(0, PITY):
  if i + 1 < PITY:
    f[i + 1] = f[i] * (1 - single_rate[i + 1])
  result[i + 1] += f[i] * single_rate[i + 1]

presum = np.zeros(PITY + 1)
expect = 0
for i in range(1, PITY + 1):
  presum[i] = presum[i - 1] + result[i]
  expect += result[i] * i
  print("%i: %.10lf %.10lf" % (i, result[i], presum[i]))
print("Expect: %.6lf" % (expect))
print("Debug: %.10lf" % (presum[PITY]))

### Draw function image
fig, ax = plt.subplots(2, 1)
ax[0].plot(np.arange(0, PITY + 1), result * 100)
ax[1].plot(np.arange(0, PITY + 1), presum * 100)
for i in range(0, 2):
  ax[i].grid(True)
  ax[i].set_ylabel('(%)')
  ax[i].set_xlim([0, PITY])
ax[0].set_ylim([0, 11])
ax[1].set_ylim([0, 102])
ax[1].set_xlabel('Pulls')
plt.savefig('result')
plt.show()