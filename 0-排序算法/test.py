import torch

a = torch.tensor((3, 3), torch.float16)
print(a)

a_T = a.T()

a_T_2 = a_T * 2