import csv

input_file = "input.txt"
output_file = "bf_functions.csv"

with open(input_file, "r") as infile, open(output_file, "w", newline="") as outfile:
    csv_writer = csv.writer(outfile)
    
    for line in infile:
        parts = line.strip().split()
        if len(parts) == 4 and parts[1] == ".text":
            name, section, address, size = parts
            size_decimal = int(size, 16)
            size_padded = f"{size_decimal:0{len(size)}d}"
            formatted_line = [f"0x{address}", "U", size_padded, name]
            csv_writer.writerow(formatted_line)
