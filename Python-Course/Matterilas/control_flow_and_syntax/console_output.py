import sys
import os

print('    line 1e to stderr  ', file=sys.stderr)
sys.stderr.write('    line 2e to stderr  \n')
sys.stderr.flush()
os.write(2, b'    line 3e to stderr  \n')
