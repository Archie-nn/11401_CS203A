# 將vscode連接至github筆記
1. 開啟vscode，按下左側的「Source Control」圖示（或使用快捷鍵Ctrl+Shift+G）。
2. 點擊「Clone Repository」按鈕。
3. 在彈出的輸入框中，輸入你的GitHub repo URL，然後按下Enter鍵。
4. 選擇本地文件夾來存儲clone的repo。
5. Clone完成後，vscode會提示你是否打開該倉庫，選擇「Open」。
6. 現在，你可以在vscode中編輯文件，並使用「Source Control」面板來提交和推送更改到GitHub。
7. 要提交更改，輸入提交信息(若未輸入信息，會導致無法儲存變更)，然後點擊「✔️」按鈕。
8. 要推送更改到GitHub，點擊「...」按鈕，然後選擇「Push」。
9. 如果是第一次推送，可能需要輸入你的GitHub憑據。
10. 完成後，你的更改將會同步到GitHub倉庫中。

# vscode上執行程式碼困難與解決方案
##困難:
1. 因使用筆電環境配置與學校電腦不同，導致無法直接執行程式碼。
2. 缺少必要的編譯器或執行環境設定。
3. 對於terminal指令不熟悉，無法順利找到輸入指令的正確位置。

##解決方案:
1. 安裝必要的編譯器，利用chatgpt 推薦下載mingw32，並裡面輸入指令下載如GCC（C/C++）編譯器。
```text
   pacman -S mingw-w64-x86_64-gcc
   pacman -S mingw-w64-x86_64-gdb
   pacman -S mingw-w64-x86_64-make
   pacman -S mingw-w64-ucrt-x86_64-toolchain
```
2. 在環境變數視窗中，將編譯器的bin資料夾路徑加入Path中。
3. 在vscode中的terminal視窗中，使用指令編譯與執行程式碼。例如:
```text
   mingw32-make c/cxx
   cd "c/cxx"
   ./hash_fn.exe
   ./hash_fn_cpp.exe
```
4. 參考README.md中的指令，確保每一步驟都正確無誤地執行。