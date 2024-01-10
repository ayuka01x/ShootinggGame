#pragma once
#include "System/Task/Task.h"
#include <string>

/// <summary>
/// クラス
/// </summary>
class AudioManager : public Task {

public:

  /// <summary>
  /// 効果音種類
  /// </summary>
  enum class EffectKind {
    
    /// <summary>
    /// バトルクリア効果音
    /// </summary>
    kBattleClearEffect,

    /// <summary>
    /// ボスの弾効果音
    /// </summary>
    kBossBulletShotEffect,

    /// <summary>
    /// ボスダメージ効果音
    /// </summary>
    kBossEnemyDamageEffect,

    /// <summary>
    /// ボス爆発効果音
    /// </summary>
    kBossEXplotionEffect,

    /// <summary>
    /// プレイヤー弾効果音
    /// </summary>
    kPlayerBulletShotEffect,

    /// <summary>
    /// プレイヤー爆発効果音
    /// </summary>
    kPlayerExplotionEffect,

    /// <summary>
    /// タックルエネミー効果音
    /// </summary>
    kTackleEnemyExplotionEffect,

    /// <summary>
    /// タイトルスタート効果音
    /// </summary>
    kTitleStartEffect,


  };

  /// <summary>
  /// BGM種類
  /// </summary>
  enum class BgmKind {
    /// <summary>
    /// バトルBGM
    /// </summary>
    kBattleBgm,

    /// <summary>
    /// タイトルBGM
    /// </summary>
    kTitleBgm,
  };

  /// <summary>
  /// コンストラクタ
  /// </summary>
  AudioManager();

  /// <summary>
  /// デストラクタ
  /// </summary>
  virtual ~AudioManager();

  /// <summary>
  /// 効果音の読み込み
  /// </summary>
  /// <param name="set_type"></param>
  void LoadSe();

  /// <summary>
  /// 効果音の再生
  /// </summary>
  /// <param name="set_type"></param>
  void  PlaySe(EffectKind set_type);

  /// <summary>
  /// 効果音の破棄
  /// </summary>
  /// <param name="set_type"></param>
  void DeleteSe();

  /// <summary>
  /// BGMの読み込み
  /// </summary>
  /// <param name="set_bgm"></param>
  void LoadBgm();

  /// <summary>
  /// BGMの再生
  /// </summary>
  /// <param name="set_bgm"></param>
  void PlayBgm(BgmKind set_bgm);

  /// <summary>
  /// BGMの破棄
  /// </summary>
  /// <param name="set_bgm"></param>
  void DeleteBgm();

  /// <summary>
  /// BGMのフェードアウト
  /// </summary>
  void FadeOutBgm(float time);

  /// <summary>
  /// BGMのフェードイン
  /// </summary>
  void FadeInBgm(float time);

  /// <summary>
  /// BGMの一時停止
  /// </summary>
  void StopBgm();

private:

  /// <summary>
  /// バトルクリア音
  /// </summary>
  int battle_clear_;

  /// <summary>
  /// ボスの弾の音
  /// </summary>
  int boss_bullet_shot_;

  /// <summary>
  /// ボスダメージ音
  /// </summary>
  int boss_damage_;

  /// <summary>
  /// ボス爆発音
  /// </summary>
  int boss_explotion_;

  /// <summary>
  /// プレイヤー弾音
  /// </summary>
  int player_bullet_;

  /// <summary>
  /// プレイヤー爆発音
  /// </summary>
  int player_explotion_;

  /// <summary>
  /// タックルエネミー爆発音
  /// </summary>
  int tackle_explotion_;

  /// <summary>
  /// タイトルスタート音
  /// </summary>
  int title_start_;

  /// <summary>
  /// バトルBGM
  /// </summary>
  int battle_bgm_;

  /// <summary>
  /// タイトルBGM
  /// </summary>
  int title_bgm_;

  /// <summary>
  /// ボリューム
  /// </summary>
  float valume_;

  /// <summary>
  /// 総フレーム数
  /// </summary>
  float total_frame_;

  /// <summary>
  /// ボリューム
  /// </summary>
  float valume_out_;
};