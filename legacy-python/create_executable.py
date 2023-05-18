import os
import shutil

# shutil.rmtree("./Release")
pyinstaller_release = """pyinstaller.exe ./main.py --onefile --noconsole -n "SpritesheetCreator" --icon=../Data/spritesheet-creator.ico --distpath ./Release"""
if __name__ == "__main__":
    os.system(pyinstaller_release)
