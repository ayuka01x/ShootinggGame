#include "System/Input/InputManager.h"
#include "DxLib.h"

//タスクマネージャーのインスタンス初期化
InputManager* InputManager::instance_ = nullptr;

/// <summary>
/// InputManager.cppのみで使う定数
/// </summary>
namespace {

  /// <summary>
  /// ゲームボタンに対応したDXライブラリ側のキー定数
  /// </summary>
  const int kDxlibKeyKind[static_cast<int>(InputManager::GameKeyKind::kNum)] = {
    KEY_INPUT_RETURN,   //Decide：決定ボタン
    KEY_INPUT_BACK,     //Cancel：キャンセルボタン
    KEY_INPUT_UP,       //Up：上ボタン
    KEY_INPUT_DOWN,     //Down：上ボタン
    KEY_INPUT_LEFT,     //Left：上ボタン
    KEY_INPUT_RIGHT,    //Right：上ボタン
    KEY_INPUT_ESCAPE,   //Pause：ポーズ
    KEY_INPUT_LSHIFT,   //PlayerMoveSlow：プレイヤー減速
    KEY_INPUT_Z,        //PlayerFire：プレイヤー弾発射
  };

  /// <summary>
  /// 何もないことを表す
  /// </summary>
  const int kNothing = 1;
}

/// <summary>
/// コンストラクタ
/// </summary>
InputManager::InputManager()
  : current_key_buffer_{ 0 }
  , pre_key_buffer_{ 0 } {
}

/// <summary>
/// デストラクタ
/// </summary>
InputManager::~InputManager() {
}

/// <summary>
/// 現在のフレームのキー情報をすべて更新
/// タスクマネージャーの更新の前に呼ぶ
/// </summary>
/// <param name="delta_time">前回実行フレームからの経過時間（秒）</param>
void InputManager::UpdateKeyStateAll(float delta_time) {

  //現在のキー情報を更新する
  GetHitKeyStateAll(current_key_buffer_);
}

/// <summary>
/// 現在のフレームのキー情報を記録
/// フレームの最後に呼ぶ
/// </summary>
/// <param name="delta_time">前回実行フレームからの経過時間（秒）</param>
void InputManager::RecordKeyStateAll(float delta_time) {

  //現在のキー情報を記録しておく
  for (int i = 0; i < kKeyBufferSize; ++i) {
    pre_key_buffer_[i] = current_key_buffer_[i];
  }
}

/// <summary>
/// 引数のキーはこのフレームで押されたか
/// </summary>
/// <param name="key_kind">調べるキー</param>
/// <returns>押されているならtrue</returns>
bool InputManager::IsPushThisFlame(GameKeyKind game_key_kind) {
  int target_key = kDxlibKeyKind[static_cast<int>(game_key_kind)];

  //current_key_buffer_ と pre_key_buffer_ の値をチェックし
  //このフレームでキーが押さた瞬間なら true を返す
  //このフレームでキーが押された瞬間ではないなら false を返す
  if ((current_key_buffer_[target_key] && kNothing) && !(pre_key_buffer_[target_key] && kNothing)) {
    return true;
  }
  else {
    return false;
  }
}

/// <summary>
/// 引数のキーは押されているか
/// </summary>
/// <param name="game_key_kind">調べるキー</param>
/// <returns>押されているならtrue</returns>
bool InputManager::IsDown(GameKeyKind game_key_kind)
{
  int target_key = kDxlibKeyKind[static_cast<int>(game_key_kind)];

  //current_key_buffer_の値をチェックし
  //現在キーが押されているなら true を返す
  //そうでないなら false を返す
  if (current_key_buffer_[target_key] && kNothing) {
    return true;
  }
  else {
    return false;
  }
}