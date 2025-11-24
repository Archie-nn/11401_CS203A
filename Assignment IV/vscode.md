# Notes on Connecting VS Code to GitHub
1. Open VS Code and click the Source Control icon on the left (or press Ctrl + Shift + G).

2. Click the Clone Repository button.

3. In the pop-up input box, enter your GitHub repository URL, then press Enter.

4. Choose a local folder to store the cloned repository.

5. After cloning, VS Code will ask whether you want to open the repository — select Open.

6. Now you can edit files in VS Code and use the Source Control panel to commit and push changes to GitHub.

7. To commit changes, enter a commit message (if you leave it empty, the commit will fail), then click the ✔️ button.

8. To push your changes to GitHub, click the … menu and select Push.

9. If this is your first time pushing, VS Code may ask for your GitHub credentials.

10. Once complete, your changes will be synchronized to your GitHub repository.

# Difficulties and Solutions When Running Code in VS Code
## Difficulties:
1. Since the environment on my laptop differs from the one at school, programs could not be executed directly.

2. Missing required compilers or runtime configurations prevented code from compiling.

3. Lack of familiarity with terminal commands made it difficult to know where to correctly input instructions.

## Solutions:
1. nstalled the necessary compilers. Following ChatGPT’s recommendation, 
   I installed MinGW/MSYS2 and used terminal commands to install GCC (C/C++ compiler):
```text
   pacman -S mingw-w64-x86_64-gcc
   pacman -S mingw-w64-x86_64-gdb
   pacman -S mingw-w64-x86_64-make
   pacman -S mingw-w64-ucrt-x86_64-toolchain
```
2. Added the compiler’s bin directory to the system PATH in the Environment Variables settings.
3. Used the integrated terminal in VS Code to compile and run programs. For example:
```text
   mingw32-make c/cxx
   cd "c/cxx"
   ./hash_fn.exe
   ./hash_fn_cpp.exe
```
4. Followed the instructions provided in README.md to ensure each step was executed correctly and without mistakes.