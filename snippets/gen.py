import json
import os
from os.path import join
from pathlib import Path


def snippetize(filename: str) -> dict:
    snippet = {}
    snippet["prefix"] = Path(filename).stem
    lines = Path(filename).read_text().splitlines()
    body = []
    processing = False

    for line in lines:
        if line.startswith("// snippet-end"):
            break
        elif line.startswith("// snippet-begin"):
            processing = True
        elif processing:
            body.append(line)

    snippet["body"] = body

    return snippet


if __name__ == "__main__":
    settings = json.load(Path("snippets_settings.json").open("r"))
    target_files = []

    for root, dirs, files in os.walk("./../src/"):
        for file_name in files:
            if Path(file_name).suffix in settings["extension"]:
                target_files.append(join(root, file_name))

    snippets = {}

    for file in target_files:
        if snippetize(file)["body"]:
            snippets[Path(file).stem] = snippetize(file)

    Path(settings["output"]).write_text(json.dumps(snippets, indent=4))
