# -*- coding: utf-8 -*-
"""
Created on Mon Jan  5 22:45:26 2015

@author: tong
"""

# -*- coding: utf-8 -*-
"""
Created on Tue Nov 11 16:36:20 2014

@author: tong
"""

import numpy as np

def sample(n):
    

    #%% sample on a solid sphere
    
    center = [(n - 1) * 0.5, (n - 1) * 0.5, (n - 1) * 0.5]
    
    d = np.zeros((n, n, n, 3), dtype=np.float32)
#    dv = np.zeros((n, n, n))   #valid or not
    
    
    for i in range(n):
        for j in range(n):
            for k in range(n):
                pos = [i, j, k]
                vec = np.subtract(pos, center)
                dis = np.linalg.norm(vec)
                val = 0
                if ( dis > 0.01):# and (dis > (n - 1) * 0.25):
                    val = vec / dis
                else:
                    val = [1,0,0]
                d[i, j, k, :] = val

    return d
    