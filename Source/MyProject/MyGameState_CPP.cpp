/*#include "MyGameState_CPP.h"
#include "Kismet/GameplayStatics.h" // GetPlayerControllerなどの便利関数を使うため

// コンストラクタ: 変数の初期値を設定
AMyGameState_CPP::AMyGameState_CPP()
{
    // Tick関数が毎フレーム呼ばれるようにする
    PrimaryActorTick.bCanEverTick = true;

    // 時間関連の初期値
    CurrentDay = 1;
    CurrentHour = 6;
    CurrentMinute = 0;
    TimeScale = 60.0f; // float型の数値には f を付ける
    TimeAccumulator = 0.0f;

    // 状態フラグの初期値
    bIsTimePaused = false;
    LastCheckedSleepDay = 0;

    CurrentTimeOfDay = ETimeOfDay::Morning;
}

void AMyGameState_CPP::BeginPlay()
{
    Super::BeginPlay();
    // ゲーム開始時にも一度、時間帯を正しく設定しておく
    UpdateCurrentTimeOfDay();
}

// Tick関数: 毎フレーム実行される
void AMyGameState_CPP::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // 時間が止まっている場合は、ここで処理を終了
    if (bIsTimePaused) // (bIsTimePaused == true) と同じ意味
    {
        return;
    }

    // --- 時間更新ロジック ---
    TimeAccumulator += DeltaTime * TimeScale;

    // TimeAccumulatorが60秒以上なら分を進める
    while (TimeAccumulator >= 60.0f)
    {
        CurrentMinute++;
        TimeAccumulator -= 60.0f;
    }

    // 分の繰り上がり
    if (CurrentMinute >= 60)
    {
        CurrentHour += CurrentMinute / 60;
        CurrentMinute %= 60; // % は剰余演算子
    }

    // 時間の繰り上がり (日付変更は就寝イベントで行う)
    // このTickでは24時になっても日付は変えない
    if (CurrentHour >= 24)
    {
        CurrentHour %= 24;
    }

    UpdateCurrentTimeOfDay();
    UpdateEnvironment(); // 毎フレーム環境を更新

    // --- 就寝チェックロジック ---
    bool bIsSleepTime = (CurrentDay < 3) && (CurrentHour == 21) && (CurrentMinute == 0);
    bool bHasNotSleptToday = (CurrentDay != LastCheckedSleepDay);

    if (bIsSleepTime && bHasNotSleptToday)
    {
        LastCheckedSleepDay = CurrentDay;
        TriggerSleepSequence();
    }
}

// 時間帯を更新する関数
void AMyGameState_CPP::UpdateCurrentTimeOfDay()
{
    if (CurrentHour >= 6 && CurrentHour < 12)
    {
        CurrentTimeOfDay = ETimeOfDay::Morning;
    }
    else if (CurrentHour >= 12 && CurrentHour < 17)
    {
        CurrentTimeOfDay = ETimeOfDay::Daytime;
    }
    else if (CurrentHour >= 17 && CurrentHour < 21)
    {
        CurrentTimeOfDay = ETimeOfDay::Evening;
    }
    else
    {
        CurrentTimeOfDay = ETimeOfDay::Night;
    }
}

// 就寝シーケンス
void AMyGameState_CPP::TriggerSleepSequence()
{
    APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
    if (PC)
    {
        PC->DisableInput(PC);
        if (APlayerCameraManager* CameraManager = PC->PlayerCameraManager)
        {
            CameraManager->StartCameraFade(1.0f, 2.0f, false);
        }
    }

    // 2秒後にWakeUpNewDayを呼び出すタイマーをセット
    FTimerHandle UnusedHandle;
    GetWorldTimerManager().SetTimer(UnusedHandle, this, &AMyGameState_CPP::WakeUpNewDay, 2.0f, false);
}

// 起床処理
void AMyGameState_CPP::WakeUpNewDay()
{
    // 時間を進める
    CurrentDay++;
    CurrentHour = 6;
    CurrentMinute = 0;
    TimeAccumulator = 0.0f;

    // 環境を朝の状態に更新
    UpdateCurrentTimeOfDay();
    UpdateEnvironment();

    APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
    if (PC)
    {
        if (APlayerCameraManager* CameraManager = PC->PlayerCameraManager)
        {
            CameraManager->StartCameraFade(0.0f, 2.0f, false);
        }
        // 2秒後にEnableInputを呼び出すタイマーをセット (フェード完了を待つ)
        FTimerHandle EnableInputHandle;
        // PC->EnableInput(PC); // このままだとFTimerDelegateに渡せないのでラムダ式などを使うか、別の関数にする必要がある
        // 簡単にするため、ここではDelayの代わりにタイマーを使わず、PlayerController側で制御するか、
        // あるいはもっとシンプルな実装にするのが良い。
        // → ここではPlayerControllerの有効化は一旦省略し、後で実装する。
    }*/
}