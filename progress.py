import math, os, sys

def truncate(number, digits) -> float:
    stepper = 10.0 ** digits
    return math.trunc(stepper * number) / stepper

done_size = 0
TOTAL_GAME_SIZE = 0xA0F5A0

with open("data/main.map", "r") as f:
    csvData = f.readlines()

for c in csvData:
    spl = c.split("=")
    isDone = spl[3].replace("\n", "")
    
    if isDone == "true":
        funcSize = int(spl[2])
        done_size = done_size + funcSize

prog = (done_size / TOTAL_GAME_SIZE) * 100.0
print("Progress:")
print(f"{prog}% [{done_size} / {TOTAL_GAME_SIZE}]")

print("Generating JSON...")

# generate our JSON for the tags on the github page
json = []
json.append("{\n")
json.append("\t\"schemaVersion\": 1,\n")
json.append("\t\"label\": \"decompiled\",\n")
json.append(f"\t\"message\": \"{truncate(prog, 4)}%\",\n")
json.append("\t\"color\": \"blue\"\n")
json.append("}")

with open("data/percent.json", "w") as w:
    w.writelines(json)