import os
import re

# Collect all problems from subfolders
def collect_problems():
    problems = []
    for root, _, files in os.walk('.'):
        for f in files:
            if f.endswith('.cpp') or f.endswith('.py'):
                folder = os.path.basename(os.path.dirname(os.path.join(root, f)))
                problems.append(folder)
    problems.sort()
    return problems

# Generate the main solved problems table
def generate_solved_table(problems):
    header = "| # | Problem Title | Solution Link |\n|---|---|---|"
    rows = [f"| {p} | {p.replace('-', ' ').title()} | [{p}](./{p}) |" for p in problems]
    return header + "\n" + "\n".join(rows)

# Generate topic tables (default difficulty = Easy)
def generate_topic_table(problems):
    header = "| Problem Name | Difficulty |\n| ------- | ------- |"
    rows = [f"| [{p}](./{p}) | Easy |" for p in problems]
    return header + "\n" + "\n".join(rows)

# Replace only the content inside a section
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
    topic_table = generate_topic_table(problems)

    # Update main solved problems section
    updated = update_section(content, "🚀 Solved Problems", solved_table)

    # Update each topic section dynamically
    topic_sections = [
        "Sorting", "Array", "String & Hash Table", "Two Pointers & Binary Search",
        "Simulation & Operations", "Linked List", "Trees & Binary Search Tree",
        "Graphs & Breadth-First / Depth-First Search", "Dynamic Programming",
        "Greedy Algorithms", "Heap / Priority Queue", "Bit Manipulation & Math",
        "Matrix & Simulation", "Backtracking & Recursion", "Trie & Advanced Data Structures"
    ]

    for section in topic_sections:
        updated = update_section(updated, section, topic_table)

    with open('README.md', 'w', encoding='utf-8') as f:
        f.write(updated)

if __name__ == "__main__":
    main()
