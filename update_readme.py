import os

def generate_readme():
    files = [f for f in os.listdir('.') if f.endswith('.py')]
    files.sort()
    with open('README.md', 'w') as readme:
        readme.write('# LeetCode Solutions\n\n')
        readme.write('Automatically updated list of solved problems:\n\n')
        for f in files:
            problem_name = f.replace('.py', '')
            readme.write(f'- [{problem_name}](./{f})\n')

if __name__ == "__main__":
    generate_readme()
