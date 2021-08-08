//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                     Test RCX Infrared Messaging
//
// This short little program tests the RCX infrared messaging capability.
//
// The ROBOTC IDE has a debugger window that can generate message numbers #1 to #6. If this program is
// running when one of these six message values is sent, then it will play a different tone for each message.
//
// The program loops forever.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma platform(RCX)

int nLastMessageReceived;
int nMsgCount = 0;


task main()
{
	ClearMessage();  // Clears any pre-existing message

	// Loop forever

	while (true)
	{
		//
		// Wait until we get a message
		//
		while (true)
		{

			if (message != 0)
			{
				nLastMessageReceived = message;
				break; // A message is here. Exit the loop!
			}
		}

		++nMsgCount;
		ClearMessage();  // So that firmware can accept a new message.
		switch (nLastMessageReceived)
		{
		case 0:       break;   // 0 is special value indicating no message received

		//
		// Do something with these message. In this case, simply play a tone
		//
		case 1:				PlaySound(soundBlip);  						SetUserDisplay(nLastMessageReceived); break;
		case 2:				PlaySound(soundBeepBeep);  				SetUserDisplay(nLastMessageReceived); break;
		case 3:				PlaySound(soundDownwardTones);  	SetUserDisplay(nLastMessageReceived); break;
		case 4:				PlaySound(soundUpwardTones);  		SetUserDisplay(nLastMessageReceived); break;
		case 5:				PlaySound(soundLowBuzz);  				SetUserDisplay(nLastMessageReceived); break;
		case 6:				PlaySound(soundFastUpwardTones);  SetUserDisplay(nLastMessageReceived); break;
		default:                                        SetUserDisplay(nLastMessageReceived); break;
		}
	}
}
