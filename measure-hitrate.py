#!/usr/bin/env python

import os, sys
import subprocess
import numpy as np

program = sys.argv[1] if len(sys.argv) == 2 else './hitrate-trivial'
hits, misses, rate = [], [], []
for _ in range(300):
    with open('wonderland.txt') as f:
        h, m, r = subprocess.check_output([program], stdin=f).split()
        hits.append(int(h))
        misses.append(int(m))
        rate.append(float(r))

print 'Hit rate: %0.3f%% (std dev: %0.3f%%)' % (100*np.mean(rate), 100*np.std(rate))
