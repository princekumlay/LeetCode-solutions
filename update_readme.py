import os

def generate_readme():
    problem_files = []
    for root, _, files in os.walk('.'):
        for f in files:
            if f.endswith('.cpp') or f.endswith('.py'):
                problem_files.append(os.path.join(root, f))

    problem_files.sort()

    with open('README.md', 'w', encoding='utf-8') as readme:
        readme.write('# LeetCode Solutions\n\n')
        readme.write('Automatically updated list of solved problems:\n\n')
        for path in problem_files:
            problem_name = os.path.basename(os.path.dirname(path))
            readme.write(f'- [{problem_name}]({path})\n')

if __name__ == "__main__":
    generate_readme()
