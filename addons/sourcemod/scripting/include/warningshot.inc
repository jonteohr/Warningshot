/*
**
*/
#if defined _WARNINGSHOT_included
 #endinput
#endif
#define _WARNINGSHOT_included

/**
* Gives the specified client a warning shot.
*
* @param client index of the victim.
* @param client index of the inflictor.
* @return true if succesful.
*/
native bool GiveClientWarningShot(int victim, int inflictor);

/**
* Called when a client has been given a warningshot.
*
* @param The victims' client index.
* @param The attackers' client index.
*/
forward void OnWarningShotGiven(int victim, int inflictor);

/**
* Checks several parameters to see if the specified client is a valid user.
*
* @param client index
* @param Allow bots?
* @param Allow dead?
* @return true if valid
*/
stock bool IsValidClient(int client, bool bAllowBots = false, bool bAllowDead = false)
{
	if(!(1 <= client <= MaxClients) || !IsClientInGame(client) || (IsFakeClient(client) && !bAllowBots) || IsClientSourceTV(client) || IsClientReplay(client) || (!bAllowDead && !IsPlayerAlive(client)))
	{
		return false;
	}
	return true;
}