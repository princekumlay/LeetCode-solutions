import os
import re

def collect_problems():
    problems = []
    for root, _, files in os.walk('.'):
        for f in files:
            if f.endswith('.cpp') or f.endswith('.py'):
                folder = os.path.basename(os.path.dirname(os.path.join(root, f)))
                problems.append(folder)
    problems.sort()
    return problems

def generate_solved_table(problems):
    header = "| # | Problem Title | Solution Link |\n|---|---|---|"
    rows = [f"| {p} | {p.replace('-', ' ').title()} | [{p}](./{p}) |" for p in problems]
    return header + "\n" + "\n".join(rows)

def generate_topics_table(problems):
    header = "| Problem Name | Difficulty |\n| ------- | ------- |"
    rows = [f"| [{p}](./{p}) | Easy |" for p in problems]
    return header + "\n" + "\n".join(rows)

def update_section(content, section_title, new_table):
    pattern = rf"(## {section_title}[\s\S]*?)(\n##|\Z)"
    return re.sub(
        pattern,
        lambda m: f"{m.group(1).splitlines()[0]}\n\n{new_table}\n\n{m.group(2)}",
        content
    )

def main():
    with open('README.md', 'r', encoding='utf-8') as f:
        content = f.read()

    problems = collect_problems()
    solved_table = generate_solved_table(problems)
    topics_table = generate_topics_table(problems)

    # Match your exact section titles
    updated = update_section(content, "🚀 Solved Problems", solved_table)
    updated = update_section(updated, "LeetCode Topics", topics_table)

    with open('README.md', 'w', encoding='utf-8') as f:
        f.write(updated)

if __name__ == "__main__":
    main()
