/*#include "MyGameState_CPP.h"
#include "Kismet/GameplayStatics.h" // GetPlayerController�Ȃǂ֗̕��֐����g������

// �R���X�g���N�^: �ϐ��̏����l��ݒ�
AMyGameState_CPP::AMyGameState_CPP()
{
    // Tick�֐������t���[���Ă΂��悤�ɂ���
    PrimaryActorTick.bCanEverTick = true;

    // ���Ԋ֘A�̏����l
    CurrentDay = 1;
    CurrentHour = 6;
    CurrentMinute = 0;
    TimeScale = 60.0f; // float�^�̐��l�ɂ� f ��t����
    TimeAccumulator = 0.0f;

    // ��ԃt���O�̏����l
    bIsTimePaused = false;
    LastCheckedSleepDay = 0;

    CurrentTimeOfDay = ETimeOfDay::Morning;
}

void AMyGameState_CPP::BeginPlay()
{
    Super::BeginPlay();
    // �Q�[���J�n���ɂ���x�A���ԑт𐳂����ݒ肵�Ă���
    UpdateCurrentTimeOfDay();
}

// Tick�֐�: ���t���[�����s�����
void AMyGameState_CPP::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // ���Ԃ��~�܂��Ă���ꍇ�́A�����ŏ������I��
    if (bIsTimePaused) // (bIsTimePaused == true) �Ɠ����Ӗ�
    {
        return;
    }

    // --- ���ԍX�V���W�b�N ---
    TimeAccumulator += DeltaTime * TimeScale;

    // TimeAccumulator��60�b�ȏ�Ȃ番��i�߂�
    while (TimeAccumulator >= 60.0f)
    {
        CurrentMinute++;
        TimeAccumulator -= 60.0f;
    }

    // ���̌J��オ��
    if (CurrentMinute >= 60)
    {
        CurrentHour += CurrentMinute / 60;
        CurrentMinute %= 60; // % �͏�]���Z�q
    }

    // ���Ԃ̌J��オ�� (���t�ύX�͏A�Q�C�x���g�ōs��)
    // ����Tick�ł�24���ɂȂ��Ă����t�͕ς��Ȃ�
    if (CurrentHour >= 24)
    {
        CurrentHour %= 24;
    }

    UpdateCurrentTimeOfDay();
    UpdateEnvironment(); // ���t���[�������X�V

    // --- �A�Q�`�F�b�N���W�b�N ---
    bool bIsSleepTime = (CurrentDay < 3) && (CurrentHour == 21) && (CurrentMinute == 0);
    bool bHasNotSleptToday = (CurrentDay != LastCheckedSleepDay);

    if (bIsSleepTime && bHasNotSleptToday)
    {
        LastCheckedSleepDay = CurrentDay;
        TriggerSleepSequence();
    }
}

// ���ԑт��X�V����֐�
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

// �A�Q�V�[�P���X
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

    // 2�b���WakeUpNewDay���Ăяo���^�C�}�[���Z�b�g
    FTimerHandle UnusedHandle;
    GetWorldTimerManager().SetTimer(UnusedHandle, this, &AMyGameState_CPP::WakeUpNewDay, 2.0f, false);
}

// �N������
void AMyGameState_CPP::WakeUpNewDay()
{
    // ���Ԃ�i�߂�
    CurrentDay++;
    CurrentHour = 6;
    CurrentMinute = 0;
    TimeAccumulator = 0.0f;

    // ���𒩂̏�ԂɍX�V
    UpdateCurrentTimeOfDay();
    UpdateEnvironment();

    APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
    if (PC)
    {
        if (APlayerCameraManager* CameraManager = PC->PlayerCameraManager)
        {
            CameraManager->StartCameraFade(0.0f, 2.0f, false);
        }
        // 2�b���EnableInput���Ăяo���^�C�}�[���Z�b�g (�t�F�[�h������҂�)
        FTimerHandle EnableInputHandle;
        // PC->EnableInput(PC); // ���̂܂܂���FTimerDelegate�ɓn���Ȃ��̂Ń����_���Ȃǂ��g�����A�ʂ̊֐��ɂ���K�v������
        // �ȒP�ɂ��邽�߁A�����ł�Delay�̑���Ƀ^�C�}�[���g�킸�APlayerController���Ő��䂷�邩�A
        // ���邢�͂����ƃV���v���Ȏ����ɂ���̂��ǂ��B
        // �� �����ł�PlayerController�̗L�����͈�U�ȗ����A��Ŏ�������B
    }*/
}