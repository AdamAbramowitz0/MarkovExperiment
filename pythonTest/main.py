import numpy as np
from train import train
import sys
def main():
       obj = train(sys.argv[1])
       obj.process()

main()