"""
This script copies Qt dependencies to the project release folder.
"""
import subprocess
import os

windeployqt_path = r"C:\Qt\6.6.0\msvc2019_64\bin\windeployqt.exe"

# Path to your application executable
app_executable = r"C:\Users\C\Desktop\spritesheet-creator\SpritesheetCreator\release\SpritesheetCreator.exe"

# Target directory for copying the dependencies
target_directory = r"C:\Users\C\Desktop\spritesheet-creator\SpritesheetCreator\QtDependencies_windeployqt"

# Create the target directory if it doesn't exist
os.makedirs(target_directory, exist_ok=True)

# Run windeployqt to copy the dependencies
command = [windeployqt_path, "--release", "--no-translations", "--dir", target_directory, app_executable]

try:
    subprocess.run(command, check=True)
    print("Qt dependencies copied successfully.")
except subprocess.CalledProcessError:
    print("Error while copying Qt dependencies.")


