void lab5_main(void)
{
    HAL_7_Segment_Init(PORTA, 0);
    HAL_KEYPAD_Init();
    while (1)
    {
        HAL_KEYPAD_Manage();
    }
}

void HAL_KEYPAD_Callouts_KeyPressNotificaton(void) //written in main
{
    if (HAL_KEYPAD_GetKey() < 10)
        HAL_7_Segment_Display(PORTA, 0, HAL_KEYPAD_GetKey());
    else
        HAL_7_Segment_TurnOff(PORTA, 0);
}