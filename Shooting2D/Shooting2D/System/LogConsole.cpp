#include "LogConsole.h"
#include <Windows.h>
#include <cstdio>

FILE* std_output;
FILE* std_errput;

/// <summary>
/// コンソールを生成する
/// </summary>
void CreateLogConsole() {
  // ログコンソール生成
  AllocConsole();

  // コンソールの設定を変更
  HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);


  // コンソールのバッファの設定を変更
  COORD dwSize;
  dwSize.X = 120;  // バッファの幅
  dwSize.Y = 3000; // バッファの高さ
  SetConsoleScreenBufferSize(hConsoleOutput, dwSize);

  // 3. 標準出力(stdout)をアクティブなコンソールに向ける
  freopen_s(&std_output, "CONOUT$", "w", stdout);

  // 4. 標準エラー出力(stderr)をアクティブなコンソールに向ける
  freopen_s(&std_errput, "CONOUT$", "w", stderr);
}

/// <summary>
/// コンソールを破棄する
/// </summary>
void DestroyLogConsole() {
  // 使用した標準出力のファイルハンドルを閉じる
  fclose(stdout);

  // 使用した標準エラー出力のファイルハンドルを閉じる
  fclose(stderr);

  // コンソールを解放
  FreeConsole();
}