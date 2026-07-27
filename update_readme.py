import os
import re

def generate_problem_list():
    problem_files = []
    for root, _, files in os.walk('.'):
        for f in files:
            if f.endswith('.cpp') or f.endswith('.py'):
                problem_files.append(os.path.join(root, f))
    problem_files.sort()

    lines = []
    for path in problem_files:
        problem_name = os.path.basename(os.path.dirname(path))
        lines.append(f'- [{problem_name}]({path})')
    return '\n'.join(lines)

def update_readme():
    with open('README.md', 'r', encoding='utf-8') as f:
        content = f.read()

    new_list = generate_problem_list()

    # Replace only the section between markers
    updated_content = re.sub(
        r'(## Solved Problems[\s\S]*?)(\n##|\Z)',
        lambda m: f"{m.group(1).splitlines()[0]}\n\n{new_list}\n\n{m.group(2)}",
        content
    )

    with open('README.md', 'w', encoding='utf-8') as f:
        f.write(updated_content)

if __name__ == "__main__":
    update_readme()
