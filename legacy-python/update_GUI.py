import subprocess

# Execute the command and capture the output
output = subprocess.check_output(["pyuic5.exe", ".\\QtDesign.ui"], universal_newlines=True)

# Write the output to the text file
with open("GUI.py", "w") as file:
    file.write(output)
