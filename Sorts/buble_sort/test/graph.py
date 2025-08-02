import sys
import seaborn as sns
import matplotlib.pyplot as plt
import pandas as pd
import re

def is_number(s):
    try:
        float(s)
        return True
    except ValueError:
        return False

def main():

    input_file = sys.argv[1]

    string_template = "N = (\d+) \s TIME = (\d+)"

    for input_file in sys.argv[1:]:
        n = []
        time = []
        with open(input_file, "r") as file:

            for line in file:
                match = re.search(rf"{string_template}", line)
                if match:
                    n.append(int(match.group(1)))
                    time.append(int(match.group(2)))
                    
        data = pd.DataFrame({
        'N': n,
        'TIME': time,
        })

        plt.figure(figsize=(16, 6))
        
        sns.lineplot(data=data, x='N', y='TIME', color="red")

        plt.title("Buble sort analysis")
        plt.xlabel('N')
        plt.ylabel("TIME microseconds")
        
        plt.savefig(f'test/buble_sort.png', dpi=300, bbox_inches='tight')

if __name__ == '__main__':
    main()
