/*
	Gamemode configuration
*/

#include "modules\header\config.txt"

#include "modules\header\colors.txt"
#include "modules\header\match.txt"
#include "modules\header\global.txt"
#include "modules\header\dialogs.txt"
#include "modules\header\fields.txt"
#include "modules\header\database.txt"

// Functions
ShowConfigDialog(playerid) {

	new string[1840];

	string = "";

	strcat(string, ""COL_PRIM"Team Names");
	strcat(string, "\n"COL_PRIM"Team Skins");
	strcat(string, "\n"COL_PRIM"A/D Settings");
	strcat(string, "\n"COL_PRIM"Restart Server");
	strcat(string, "\n"COL_PRIM"Max Ping");
	strcat(string, "\n"COL_PRIM"Max Packetloss");
	strcat(string, "\n"COL_PRIM"Min FPS");

	new isrestricted = 0;
	for(new i = 0; i < sizeof(GroupAccessPassword);i ++)
	{
		if(strlen(GroupAccessPassword[i]) > 0)
		{
			isrestricted = 1;
			break;
		}
	}
	if(isrestricted == 1) {
		strcat(string, "\n{FF6666}Group Access restricted");
	} else {
		strcat(string, "\n{66FF66}Group Access unrestricted");
	}

	if(ServerLocked == true) {
		strcat(string, "\n{FF6666}Server Locked");
	} else {
		strcat(string, "\n{66FF66}Server Unlocked");
	}

	if(AntiSpam == true) {
		strcat(string, "\n{66FF66}Anti-Spam");
	} else {
		strcat(string, "\n{FF6666}Anti-Spam");
	}

	if(AutoBal == true) {
		strcat(string, "\n{66FF66}Auto-Balance");
	} else {
		strcat(string, "\n{FF6666}Auto-Balance");
	}

	if(AutoPause == true) {
		strcat(string, "\n{66FF66}Auto-Pause");
	} else {
		strcat(string, "\n{FF6666}Auto-Pause");
	}

	if(LobbyGuns == true) {
		strcat(string, "\n{66FF66}Guns in Lobby");
	} else {
		strcat(string, "\n{FF6666}Guns in Lobby");
	}

	if(DefendersSeeVehiclesBlips == true)
		strcat(string, "\n{66FF66}Defenders see vehicle blips [Disable]");
	else
		strcat(string, "\n{FF6666}Defenders don't see vehicle blips [Enable]");

	if(LeagueAllowed == true)
		strcat(string, "\n{66FF66}League system");
	else
		strcat(string, "\n{FF6666}League system");

	if(CPInArena == true)
		strcat(string, "\n{66FF66}Checkpoint in arena");
	else
		strcat(string, "\n{FF6666}Checkpoint in arena");

	if(AntiMacros == true)
		strcat(string, "\n{66FF66}Anti-macros system");
	else
		strcat(string, "\n{FF6666}Anti-macros system");

	if(DeadBodies == true)
		strcat(string, "\n{66FF66}Dead bodies");
	else
		strcat(string, "\n{FF6666}Dead bodies");

	if(DeathCamera == true)
		strcat(string, "\n{66FF66}Death camera and its textdraws");
	else
		strcat(string, "\n{FF6666}Death camera and its textdraws");

	if(ShowHPBars == true)
		strcat(string, "\n{66FF66}HP Bars");
	else
		strcat(string, "\n{FF6666}HP Bars");

	if(LeagueShop == true)
		strcat(string, "\n{66FF66}League shop (/shop)");
	else
		strcat(string, "\n{FF6666}League shop (/shop)");

	if(GunmenuRestrictions == true)
		strcat(string, "\n{66FF66}Gunmenu selection restriction");
	else
		strcat(string, "\n{FF6666}Gunmenu selection restriction");

	if(MeleeAllowed == true)
		strcat(string, "\n{66FF66}Melee weapon menu");
	else
		strcat(string, "\n{FF6666}Melee weapon menu");

	if(AutoRoundStarter == true)
		strcat(string, "\n{66FF66}Auto round starter");
	else
		strcat(string, "\n{FF6666}Auto round starter");
		
	if(RandomDeathMessages == true)
		strcat(string, "\n{66FF66}Random Death Messages");
	else
		strcat(string, "\n{FF6666}Random Death Messages");
		
	if(SightseeingInClassSelection == true)
		strcat(string, "\n{66FF66}Sightseeing In Class Selection");
	else
		strcat(string, "\n{FF6666}Sightseeing In Class Selection");
		
	if(VehicleHealthTextdraw == true)
		strcat(string, "\n{66FF66}Vehicle Health Information");
	else
		strcat(string, "\n{FF6666}Vehicle Health Information");
		
	if(SyncAbuse == true)
		strcat(string, "\n{66FF66}Sync Abuse");
	else
		strcat(string, "\n{FF6666}Sync Abuse");
		
	if(ScreenFlashing == true)
		strcat(string, "\n{66FF66}CP Screen Flashing");
	else
		strcat(string, "\n{FF6666}CP Screen Flashing");
		
	if(DefendersWithVehicles == true)
		strcat(string, "\n{66FF66}Defenders Can Use Vehicles");
	else
		strcat(string, "\n{FF6666}Defenders Can Use Vehicles");

    ShowPlayerDialog(playerid, DIALOG_CONFIG, DIALOG_STYLE_LIST, ""COL_PRIM"Config Settings", string, "OK", "Cancel");
    return 1;
}

LoadConfig()
{
	new iString[128];
	new Float:DBVersion;
	new Float:DBWasUpdated = 0.0;
    new DBResult:res = db_query(sqliteconnection, "SELECT * FROM Configs");
    Skin[NON] = 0;

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // Attacker Skin
    Skin[ATTACKER] = strval(iString);
	db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // Attacker Sub Skin
    Skin[ATTACKER_SUB] = strval(iString);
	db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // Defender Skin
    Skin[DEFENDER] = strval(iString);
	db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // Defender Sub Skin
    Skin[DEFENDER_SUB] = strval(iString);
	db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // Referee Skin
    Skin[REFEREE] = strval(iString);
	db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // Server Weather
    MainWeather = strval(iString);
	db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // Server Time
    MainTime = strval(iString);
	db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // CP Time
    ConfigCPTime = strval(iString);
	db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // Round Time
    ConfigRoundTime = strval(iString);
	db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // Total Rounds
    TotalRounds = strval(iString);
	db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // Maximum Packetloss
    Max_Packetloss = floatstr(iString);
	db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // Maximum Ping
    Max_Ping = strval(iString);
	db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // Minimum FPS
    Min_FPS = strval(iString);
	db_next_row(res);

    db_get_field_assoc(res, "Value", iString, sizeof(iString)); // Main Spawn
	sscanf(iString, "p,ffffd", MainSpawn[0], MainSpawn[1], MainSpawn[2], MainSpawn[3], MainInterior);
    db_next_row(res);

    db_get_field_assoc(res, "Value", iString, sizeof(iString));
    sscanf(iString, "p,dd", RoundAR, RoundHP);
	db_next_row(res);

    db_get_field_assoc(res, "Value", iString, sizeof(iString)); // Main Background Colour
    MAIN_BACKGROUND_COLOUR = strval(iString);
	db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // Main Text Colour
	sscanf(iString, "s", MAIN_TEXT_COLOUR);
	db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // Color Scheme ID
 	format( ColScheme, 10, "{%s}", iString );
 	db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // League allowed
	LeagueAllowed = (strval(iString) == 1 ? true : false);
    db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // CP in arena
    CPInArena = (strval(iString) == 1 ? true : false);
    db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // AntiMacros
    AntiMacros = (strval(iString) == 1 ? true : false);
    db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // DeadBodies
    DeadBodies = (strval(iString) == 1 ? true : false);
    db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // DeathCamera
    DeathCamera = (strval(iString) == 1 ? true : false);
    db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // ShowHPBars
    ShowHPBars = (strval(iString) == 1 ? true : false);
    db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // LeagueShop
    LeagueShop = (strval(iString) == 1 ? true : false);
    db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // MeleeAllowed
    MeleeAllowed = (strval(iString) == 1 ? true : false);
    db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // CurrentBaseSet
	sscanf(iString, "s", CurrentBaseSet);
    db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // AutoRoundStarter
    AutoRoundStarter = (strval(iString) == 1 ? true : false);
    db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // Database Version
	DBVersion = floatstr(iString);
    db_next_row(res);

	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // Game speed
    GAME_SPEED = strval(iString);
    db_next_row(res);
	
	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // RandomDeathMessages
    RandomDeathMessages = (strval(iString) == 1 ? true : false);
    db_next_row(res);
	
	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // SightseeingInClassSelection
    SightseeingInClassSelection = (strval(iString) == 1 ? true : false);
    db_next_row(res);
	
	db_get_field_assoc(res, "Value", iString, sizeof(iString)); // VehicleHealthTextdraw
    VehicleHealthTextdraw = (strval(iString) == 1 ? true : false);
    db_next_row(res);
	
	///////////////////////////////////////////////////////////////////////////////////////////
	
	/*
	    Important Notice: After 1.12 version, it was decided to use database version different from gamemode version,
		because of float assignation problems. For ex. assigning DBWasUpdated to 1.16 returns 1.159999.
	*/
	
	if(DBVersion >= 1.12)
	{
		db_get_field_assoc(res, "Value", iString, sizeof(iString));
        SyncAbuse = (strval(iString) == 1 ? true : false);
        db_next_row(res);
		
		db_get_field_assoc(res, "Value", iString, sizeof(iString));
        ScreenFlashing = (strval(iString) == 1 ? true : false);
        db_next_row(res);
	}
	else
	{
	    db_free_result(db_query(sqliteconnection, "INSERT INTO Configs (Option, Value) VALUES('SyncAbuse', 1)"));
		db_free_result(db_query(sqliteconnection, "INSERT INTO Configs (Option, Value) VALUES('ScreenFlash', 1)"));
		
		SyncAbuse = true;
	    ScreenFlashing = true;
		DBWasUpdated = 1.12;
	}
	
	if(DBVersion >= 2.0)
	{
		db_get_field_assoc(res, "Value", iString, sizeof(iString));
        DefendersWithVehicles = (strval(iString) == 1 ? true : false);
        db_next_row(res);
	}
	else
	{
	    db_free_result(db_query(sqliteconnection, "INSERT INTO Configs (Option, Value) VALUES('DefVehicles', 0)"));
		
		DefendersWithVehicles = false;
		DBWasUpdated = 2.0;
	}
	
	///////////////////////////////////////////////////////////////////////////////////////////
	db_free_result(res);
	
	if(DBWasUpdated > 0.00)
	{
	    db_query(sqliteconnection, sprintf("UPDATE Configs SET Value = %.02f WHERE Option = 'GMVersion'", DBWasUpdated));
	    printf("Server Config Loaded. Database Was Updated To Version %.02f.", DBWasUpdated);
	}
	else
	{
	    printf("Server Config Loaded. Current Database Version: %.02f",DBVersion);
	}
}
