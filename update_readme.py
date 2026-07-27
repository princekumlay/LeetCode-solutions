import os
import re

def collect_problems():
    problems = []
    for root, _, files in os.walk('.'):
        for f in files:
            if f.endswith('.cpp') or f.endswith('.py'):
                folder = os.path.basename(os.path.dirname(os.path.join(root, f)))
                problems.append(f"- [{folder}]({os.path.join(root, f)})")
    problems.sort()
    return '\n'.join(problems)

def update_section(content, section_title, new_list):
    pattern = rf"(## {section_title}[\s\S]*?)(\n##|\Z)"
    return re.sub(
        pattern,
        lambda m: f"{m.group(1).splitlines()[0]}\n\n{new_list}\n\n{m.group(2)}",
        content
    )

def main():
    with open('README.md', 'r', encoding='utf-8') as f:
        content = f.read()

    new_list = collect_problems()
    updated = update_section(content, "Solved Problems", new_list)
    updated = update_section(updated, "Topic-wise Questions", new_list)

    with open('README.md', 'w', encoding='utf-8') as f:
        f.write(updated)

if __name__ == "__main__":
    main()
