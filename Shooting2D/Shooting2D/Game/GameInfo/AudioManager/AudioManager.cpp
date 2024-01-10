#include "AudioManager.h"
#include "DxLib.h"
#include <iostream>
/// <summary>
/// 名前空間
/// </summary>
namespace {

  /// <summary>
  /// バトルBGM
  /// </summary>
  const char* kBattle = "Assets/Audio/BattleBgm.mp3";

  /// <summary>
  /// バトルクリア効果音
  /// </summary>
  const char* kBattleClear = "Assets/Audio/BattleClearSe.mp3";

  /// <summary>
  /// ボスの弾効果音
  /// </summary>
  const char* kBossBulletShot = "Assets/Audio/BossEnemyBulletShotSe.mp3";

  /// <summary>
  /// ボスダメージ効果音
  /// </summary>
  const char* kBossEnemyDamage = "Assets/Audio/BossEnemyDamageSe.mp3";

  /// <summary>
  /// ボス爆発効果音
  /// </summary>
  const char* kBossEXplotion = "Assets/Audio/BossEnemyExplosionSe.mp3";

  /// <summary>
  /// プレイヤー弾効果音
  /// </summary>
  const char* kPlayerBulletShot = "Assets/Audio/PlayerBulletShotSe.mp3";

  /// <summary>
  /// プレイヤー爆発効果音
  /// </summary>
  const char* kPlayerExplotion = "Assets/Audio/PlayerExplosionSe.mp3";

  /// <summary>
  /// タックルエネミー効果音
  /// </summary>
  const char* kTackleEnemyExplotion = "Assets/Audio/TackleEnemyExplosionSe.mp3";

  /// <summary>
  /// タイトルBGM
  /// </summary>
  const char* kTitle = "Assets/Audio/TitleBgm.mp3";

  /// <summary>
  /// タイトルスタート効果音
  /// </summary>
  const char* kTitleStart = "Assets/Audio/TitleStartSe.mp3";

  /// <summary>
  /// フレームレート
  /// </summary>
  const int kFrame = 60;

  /// <summary>
  /// フェードアウトval
  /// </summary>
  const int kFadeOutValume = 120;

  /// <summary>
  /// フェードインval
  /// </summary>
  const int kFadeInValume = 100;

  /// <summary>
  /// maxボリューム
  /// </summary>
  const int kFullValume = 255;
}
/// <summary>
/// コンストラクタ
/// </summary>
AudioManager::AudioManager()
  : battle_clear_(0)
  , boss_bullet_shot_(0)
  , boss_damage_(0)
  , boss_explotion_(0)
  , player_bullet_(0)
  , player_explotion_(0)
  , tackle_explotion_(0)
  , title_start_(0)
  , battle_bgm_(0)
  , title_bgm_(0)
  , total_frame_(0)
  , valume_(0)
  , valume_out_(kFullValume){
}

/// <summary>
/// デストラクタ
/// </summary>
AudioManager::~AudioManager() {

}

/// <summary>
/// 効果音の読み込み
/// </summary>
/// <param name="set_type"></param>
void AudioManager::LoadSe() {
  battle_clear_ = LoadSoundMem(kBattleClear);
  boss_bullet_shot_ = LoadSoundMem(kBossBulletShot);
  boss_damage_ = LoadSoundMem(kBossEnemyDamage);
  boss_explotion_ = LoadSoundMem(kBossEXplotion);
  player_bullet_ = LoadSoundMem(kPlayerBulletShot);
  player_explotion_ = LoadSoundMem(kPlayerExplotion);
  tackle_explotion_ = LoadSoundMem(kTackleEnemyExplotion);
  title_start_ = LoadSoundMem(kTitleStart);
}

/// <summary>
/// 効果音の再生
/// </summary>
/// <param name="set_type"></param>
void AudioManager::PlaySe(EffectKind set_type) {

  if (set_type == AudioManager::EffectKind::kBattleClearEffect) {
    PlaySoundMem(battle_clear_, DX_PLAYTYPE_BACK);
  }
  
  if (set_type == AudioManager::EffectKind::kBossBulletShotEffect) {
    PlaySoundMem(boss_bullet_shot_, DX_PLAYTYPE_BACK);
  }
  
  if (set_type == AudioManager::EffectKind::kBossEnemyDamageEffect) {
    PlaySoundMem(boss_damage_, DX_PLAYTYPE_BACK);
  }
  
  if (set_type == AudioManager::EffectKind::kBossEXplotionEffect) {
    PlaySoundMem(boss_explotion_, DX_PLAYTYPE_BACK);
  }
  
  if (set_type == AudioManager::EffectKind::kPlayerBulletShotEffect) {
    PlaySoundMem(player_bullet_, DX_PLAYTYPE_BACK);
  }
  
  if (set_type == AudioManager::EffectKind::kPlayerExplotionEffect) {
    PlaySoundMem(player_explotion_, DX_PLAYTYPE_BACK);
  }
  
  if (set_type == AudioManager::EffectKind::kTackleEnemyExplotionEffect) {
    PlaySoundMem(tackle_explotion_, DX_PLAYTYPE_BACK);
  }
  
  if (set_type == AudioManager::EffectKind::kTitleStartEffect) {
    PlaySoundMem(title_start_, DX_PLAYTYPE_BACK);
  }
  
}

/// <summary>
/// 効果音の破棄
/// </summary>
/// <param name="set_type"></param>
void AudioManager::DeleteSe() {
  DeleteSoundMem(battle_clear_);
  DeleteSoundMem(boss_bullet_shot_);
  DeleteSoundMem(boss_damage_);
  DeleteSoundMem(boss_explotion_);
  DeleteSoundMem(player_bullet_);
  DeleteSoundMem(player_explotion_);
  DeleteSoundMem(tackle_explotion_);
  DeleteSoundMem(title_start_);
}

/// <summary>
/// BGMの読み込み
/// </summary>
/// <param name="set_bgm"></param>
void AudioManager::LoadBgm() {
  battle_bgm_ = LoadSoundMem(kBattle);
  title_bgm_ = LoadSoundMem(kTitle);
}

/// <summary>
/// BGMの再生
/// </summary>
/// <param name="set_bgm"></param>
void AudioManager::PlayBgm(BgmKind set_bgm) {
  if (set_bgm == BgmKind::kBattleBgm) {
    PlaySoundMem(battle_bgm_, DX_PLAYTYPE_BACK);
  }
  
  if (set_bgm == BgmKind::kTitleBgm) {
    PlaySoundMem(title_bgm_, DX_PLAYTYPE_BACK);
  } 
}

/// <summary>
/// BGMの破棄
/// </summary>
/// <param name="set_bgm"></param>
void AudioManager::DeleteBgm() {
  DeleteSoundMem(battle_bgm_);
  DeleteSoundMem(title_bgm_);
}

/// <summary>
/// BGMのフェードアウト
/// </summary>
void AudioManager::FadeOutBgm(float time) {

  total_frame_ = time * -kFrame;
  valume_out_ += kFadeOutValume / total_frame_;
  if (valume_out_ <= kFadeOutValume) {
    valume_out_ = kFadeOutValume;
  }
  ChangeVolumeSoundMem(valume_out_, battle_bgm_);
  std::cout << "valume_out:" << valume_out_ << std::endl;
}

/// <summary>
/// BGMのフェードイン
/// </summary>
void AudioManager::FadeInBgm(float time) {
  total_frame_ = time * kFrame;
  valume_ += kFadeInValume / total_frame_;
  if (valume_ >= kFadeInValume) {
    valume_ = kFadeInValume;
  }
  ChangeVolumeSoundMem(valume_, title_bgm_);
  std::cout << "valume_:" << valume_ << std::endl;
}

/// <summary>
/// BGMの一時停止
/// </summary>
void AudioManager::StopBgm() {
  ChangeVolumeSoundMem(0, title_bgm_);
  ChangeVolumeSoundMem(0, battle_bgm_);
}
