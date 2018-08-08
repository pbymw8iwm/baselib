/*
** Lua binding: Player
** Generated automatically by tolua++-1.0.92 on 06/24/14 19:37:00.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Player_open (lua_State* tolua_S);

#include "common.h"
#include "partner.h"
#include "player.h"
#include "fight.h" 
#include "skill.h"
#include "fightreport.h"
#include "common.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"PartnerLevelInfo");
 tolua_usertype(tolua_S,"Net_Packet");
 tolua_usertype(tolua_S,"FightAttack");
 tolua_usertype(tolua_S,"PlayerPartner");
 tolua_usertype(tolua_S,"FightField");
 tolua_usertype(tolua_S,"FightUnit");
 tolua_usertype(tolua_S,"Player");
 tolua_usertype(tolua_S,"ATTACK_EFFECT");
 tolua_usertype(tolua_S,"FightForce");
 tolua_usertype(tolua_S,"SkillTem");
 tolua_usertype(tolua_S,"FightProp");
 tolua_usertype(tolua_S,"FIGHT_FIELD_TYPE");
 tolua_usertype(tolua_S,"VictimerInfo");
}

/* method: addExp of class  Player */
#ifndef TOLUA_DISABLE_tolua_Player_Player_addExp00
static int tolua_Player_Player_addExp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Player",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Player* self = (Player*)  tolua_tousertype(tolua_S,1,0);
  int exp = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addExp'", NULL);
#endif
  {
   self->addExp(exp);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addExp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createPakcet of class  Player */
#ifndef TOLUA_DISABLE_tolua_Player_Player_createPakcet00
static int tolua_Player_Player_createPakcet00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Player",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Player* self = (Player*)  tolua_tousertype(tolua_S,1,0);
  int cmd = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createPakcet'", NULL);
#endif
  {
   Net_Packet* tolua_ret = (Net_Packet*)  self->createPakcet(cmd);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Net_Packet");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createPakcet'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendPacket of class  Player */
#ifndef TOLUA_DISABLE_tolua_Player_Player_sendPacket00
static int tolua_Player_Player_sendPacket00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Player",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Net_Packet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Player* self = (Player*)  tolua_tousertype(tolua_S,1,0);
  Net_Packet* new_packet = ((Net_Packet*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendPacket'", NULL);
#endif
  {
   self->sendPacket(new_packet);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendPacket'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: toString of class  Player */
#ifndef TOLUA_DISABLE_tolua_Player_Player_toString00
static int tolua_Player_Player_toString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Player",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Player* self = (Player*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'toString'", NULL);
#endif
  {
   string tolua_ret = (string)  self->toString();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rewardGift of class  Player */
#ifndef TOLUA_DISABLE_tolua_Player_Player_rewardGift00
static int tolua_Player_Player_rewardGift00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Player",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Player* self = (Player*)  tolua_tousertype(tolua_S,1,0);
  const std::string strGift = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rewardGift'", NULL);
#endif
  {
   int tolua_ret = (int)  self->rewardGift(strGift);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)strGift);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rewardGift'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: postBulletin of class  Player */
#ifndef TOLUA_DISABLE_tolua_Player_Player_postBulletin00
static int tolua_Player_Player_postBulletin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Player",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Player* self = (Player*)  tolua_tousertype(tolua_S,1,0);
  const string strRewards = ((const string)  tolua_tocppstring(tolua_S,2,0));
  const string strMsg = ((const string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'postBulletin'", NULL);
#endif
  {
   self->postBulletin(strRewards,strMsg);
   tolua_pushcppstring(tolua_S,(const char*)strRewards);
   tolua_pushcppstring(tolua_S,(const char*)strMsg);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'postBulletin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: deleteViewIntrest of class  Player */
#ifndef TOLUA_DISABLE_tolua_Player_Player_deleteViewIntrest00
static int tolua_Player_Player_deleteViewIntrest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Player",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Player* self = (Player*)  tolua_tousertype(tolua_S,1,0);
  int activetyIndex = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'deleteViewIntrest'", NULL);
#endif
  {
   self->deleteViewIntrest(activetyIndex);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'deleteViewIntrest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isInViewInstrest of class  Player */
#ifndef TOLUA_DISABLE_tolua_Player_Player_isInViewInstrest00
static int tolua_Player_Player_isInViewInstrest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Player",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Player* self = (Player*)  tolua_tousertype(tolua_S,1,0);
  int activetyIndex = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isInViewInstrest'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isInViewInstrest(activetyIndex);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isInViewInstrest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mainPartnerId of class  Player */
#ifndef TOLUA_DISABLE_tolua_get_Player_unsigned_mainPartnerId
static int tolua_get_Player_unsigned_mainPartnerId(lua_State* tolua_S)
{
  Player* self = (Player*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mainPartnerId'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->mainPartnerId);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mainPartnerId of class  Player */
#ifndef TOLUA_DISABLE_tolua_set_Player_unsigned_mainPartnerId
static int tolua_set_Player_unsigned_mainPartnerId(lua_State* tolua_S)
{
  Player* self = (Player*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mainPartnerId'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mainPartnerId = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: read_uint8 of class  Net_Packet */
#ifndef TOLUA_DISABLE_tolua_Player_Net_Packet_read_uint800
static int tolua_Player_Net_Packet_read_uint800(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Net_Packet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Net_Packet* self = (Net_Packet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'read_uint8'", NULL);
#endif
  {
   int tolua_ret = (int)  self->read_uint8();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'read_uint8'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: read_uint16 of class  Net_Packet */
#ifndef TOLUA_DISABLE_tolua_Player_Net_Packet_read_uint1600
static int tolua_Player_Net_Packet_read_uint1600(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Net_Packet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Net_Packet* self = (Net_Packet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'read_uint16'", NULL);
#endif
  {
   int tolua_ret = (int)  self->read_uint16();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'read_uint16'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: read_uint32 of class  Net_Packet */
#ifndef TOLUA_DISABLE_tolua_Player_Net_Packet_read_uint3200
static int tolua_Player_Net_Packet_read_uint3200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Net_Packet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Net_Packet* self = (Net_Packet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'read_uint32'", NULL);
#endif
  {
   int tolua_ret = (int)  self->read_uint32();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'read_uint32'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: read_string of class  Net_Packet */
#ifndef TOLUA_DISABLE_tolua_Player_Net_Packet_read_string00
static int tolua_Player_Net_Packet_read_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Net_Packet",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Net_Packet* self = (Net_Packet*)  tolua_tousertype(tolua_S,1,0);
  std::string str = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  int nDataLen = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'read_string'", NULL);
#endif
  {
   int tolua_ret = (int)  self->read_string(str,nDataLen);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)str);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'read_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: write_uint8 of class  Net_Packet */
#ifndef TOLUA_DISABLE_tolua_Player_Net_Packet_write_uint800
static int tolua_Player_Net_Packet_write_uint800(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Net_Packet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Net_Packet* self = (Net_Packet*)  tolua_tousertype(tolua_S,1,0);
  int data = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'write_uint8'", NULL);
#endif
  {
   self->write_uint8(data);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'write_uint8'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: write_uint16 of class  Net_Packet */
#ifndef TOLUA_DISABLE_tolua_Player_Net_Packet_write_uint1600
static int tolua_Player_Net_Packet_write_uint1600(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Net_Packet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Net_Packet* self = (Net_Packet*)  tolua_tousertype(tolua_S,1,0);
  int data = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'write_uint16'", NULL);
#endif
  {
   self->write_uint16(data);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'write_uint16'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: write_uint32 of class  Net_Packet */
#ifndef TOLUA_DISABLE_tolua_Player_Net_Packet_write_uint3200
static int tolua_Player_Net_Packet_write_uint3200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Net_Packet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Net_Packet* self = (Net_Packet*)  tolua_tousertype(tolua_S,1,0);
  int data = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'write_uint32'", NULL);
#endif
  {
   self->write_uint32(data);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'write_uint32'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: write_string of class  Net_Packet */
#ifndef TOLUA_DISABLE_tolua_Player_Net_Packet_write_string00
static int tolua_Player_Net_Packet_write_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Net_Packet",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Net_Packet* self = (Net_Packet*)  tolua_tousertype(tolua_S,1,0);
  const std::string str = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'write_string'", NULL);
#endif
  {
   self->write_string(str);
   tolua_pushcppstring(tolua_S,(const char*)str);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'write_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: onScriptActivetyChange */
#ifndef TOLUA_DISABLE_tolua_Player_onScriptActivetyChange00
static int tolua_Player_onScriptActivetyChange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int activetyIndex = ((int)  tolua_tonumber(tolua_S,1,0));
  bool bUpdate = ((bool)  tolua_toboolean(tolua_S,2,0));
  {
   onScriptActivetyChange(activetyIndex,bUpdate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onScriptActivetyChange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: postDbReq */
#ifndef TOLUA_DISABLE_tolua_Player_postDbReq00
static int tolua_Player_postDbReq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_iscppstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string strSql = ((const std::string)  tolua_tocppstring(tolua_S,1,0));
  int reqType = ((int)  tolua_tonumber(tolua_S,2,0));
  bool bUpdate = ((bool)  tolua_toboolean(tolua_S,3,0));
  {
   postDbReq(strSql,reqType,bUpdate);
   tolua_pushcppstring(tolua_S,(const char*)strSql);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'postDbReq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ninjitsu of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_get_PartnerLevelInfo_unsigned_ninjitsu
static int tolua_get_PartnerLevelInfo_unsigned_ninjitsu(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ninjitsu'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ninjitsu);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ninjitsu of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_set_PartnerLevelInfo_unsigned_ninjitsu
static int tolua_set_PartnerLevelInfo_unsigned_ninjitsu(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ninjitsu'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ninjitsu = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: magic of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_get_PartnerLevelInfo_unsigned_magic
static int tolua_get_PartnerLevelInfo_unsigned_magic(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'magic'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->magic);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: magic of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_set_PartnerLevelInfo_unsigned_magic
static int tolua_set_PartnerLevelInfo_unsigned_magic(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'magic'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->magic = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: leixlaeg of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_get_PartnerLevelInfo_unsigned_leixlaeg
static int tolua_get_PartnerLevelInfo_unsigned_leixlaeg(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'leixlaeg'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->leixlaeg);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: leixlaeg of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_set_PartnerLevelInfo_unsigned_leixlaeg
static int tolua_set_PartnerLevelInfo_unsigned_leixlaeg(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'leixlaeg'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->leixlaeg = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: hp of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_get_PartnerLevelInfo_unsigned_hp
static int tolua_get_PartnerLevelInfo_unsigned_hp(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hp'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->hp);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: hp of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_set_PartnerLevelInfo_unsigned_hp
static int tolua_set_PartnerLevelInfo_unsigned_hp(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hp'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->hp = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: chakra of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_get_PartnerLevelInfo_unsigned_chakra
static int tolua_get_PartnerLevelInfo_unsigned_chakra(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'chakra'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->chakra);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: chakra of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_set_PartnerLevelInfo_unsigned_chakra
static int tolua_set_PartnerLevelInfo_unsigned_chakra(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'chakra'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->chakra = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: phyattack of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_get_PartnerLevelInfo_unsigned_phyattack
static int tolua_get_PartnerLevelInfo_unsigned_phyattack(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'phyattack'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->phyattack);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: phyattack of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_set_PartnerLevelInfo_unsigned_phyattack
static int tolua_set_PartnerLevelInfo_unsigned_phyattack(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'phyattack'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->phyattack = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: magattack of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_get_PartnerLevelInfo_unsigned_magattack
static int tolua_get_PartnerLevelInfo_unsigned_magattack(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'magattack'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->magattack);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: magattack of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_set_PartnerLevelInfo_unsigned_magattack
static int tolua_set_PartnerLevelInfo_unsigned_magattack(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'magattack'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->magattack = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: phydefence of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_get_PartnerLevelInfo_unsigned_phydefence
static int tolua_get_PartnerLevelInfo_unsigned_phydefence(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'phydefence'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->phydefence);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: phydefence of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_set_PartnerLevelInfo_unsigned_phydefence
static int tolua_set_PartnerLevelInfo_unsigned_phydefence(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'phydefence'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->phydefence = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: magdefence of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_get_PartnerLevelInfo_unsigned_magdefence
static int tolua_get_PartnerLevelInfo_unsigned_magdefence(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'magdefence'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->magdefence);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: magdefence of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_set_PartnerLevelInfo_unsigned_magdefence
static int tolua_set_PartnerLevelInfo_unsigned_magdefence(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'magdefence'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->magdefence = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: skillattack of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_get_PartnerLevelInfo_unsigned_skillattack
static int tolua_get_PartnerLevelInfo_unsigned_skillattack(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skillattack'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->skillattack);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: skillattack of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_set_PartnerLevelInfo_unsigned_skillattack
static int tolua_set_PartnerLevelInfo_unsigned_skillattack(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skillattack'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->skillattack = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: skilldefence of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_get_PartnerLevelInfo_unsigned_skilldefence
static int tolua_get_PartnerLevelInfo_unsigned_skilldefence(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skilldefence'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->skilldefence);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: skilldefence of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_set_PartnerLevelInfo_unsigned_skilldefence
static int tolua_set_PartnerLevelInfo_unsigned_skilldefence(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skilldefence'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->skilldefence = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: hitrate of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_get_PartnerLevelInfo_unsigned_hitrate
static int tolua_get_PartnerLevelInfo_unsigned_hitrate(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hitrate'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->hitrate);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: hitrate of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_set_PartnerLevelInfo_unsigned_hitrate
static int tolua_set_PartnerLevelInfo_unsigned_hitrate(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hitrate'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->hitrate = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: dodgerate of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_get_PartnerLevelInfo_unsigned_dodgerate
static int tolua_get_PartnerLevelInfo_unsigned_dodgerate(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dodgerate'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->dodgerate);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: dodgerate of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_set_PartnerLevelInfo_unsigned_dodgerate
static int tolua_set_PartnerLevelInfo_unsigned_dodgerate(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dodgerate'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->dodgerate = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: crirate of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_get_PartnerLevelInfo_unsigned_crirate
static int tolua_get_PartnerLevelInfo_unsigned_crirate(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'crirate'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->crirate);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: crirate of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_set_PartnerLevelInfo_unsigned_crirate
static int tolua_set_PartnerLevelInfo_unsigned_crirate(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'crirate'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->crirate = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: resistcrirate of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_get_PartnerLevelInfo_unsigned_resistcrirate
static int tolua_get_PartnerLevelInfo_unsigned_resistcrirate(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'resistcrirate'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->resistcrirate);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: resistcrirate of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_set_PartnerLevelInfo_unsigned_resistcrirate
static int tolua_set_PartnerLevelInfo_unsigned_resistcrirate(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'resistcrirate'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->resistcrirate = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: blockratio of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_get_PartnerLevelInfo_unsigned_blockratio
static int tolua_get_PartnerLevelInfo_unsigned_blockratio(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'blockratio'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->blockratio);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: blockratio of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_set_PartnerLevelInfo_unsigned_blockratio
static int tolua_set_PartnerLevelInfo_unsigned_blockratio(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'blockratio'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->blockratio = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: wreckratio of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_get_PartnerLevelInfo_unsigned_wreckratio
static int tolua_get_PartnerLevelInfo_unsigned_wreckratio(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'wreckratio'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->wreckratio);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: wreckratio of class  PartnerLevelInfo */
#ifndef TOLUA_DISABLE_tolua_set_PartnerLevelInfo_unsigned_wreckratio
static int tolua_set_PartnerLevelInfo_unsigned_wreckratio(lua_State* tolua_S)
{
  PartnerLevelInfo* self = (PartnerLevelInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'wreckratio'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->wreckratio = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ninjitsu of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_ninjitsu
static int tolua_get_FightProp_unsigned_ninjitsu(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ninjitsu'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ninjitsu);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ninjitsu of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_ninjitsu
static int tolua_set_FightProp_unsigned_ninjitsu(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ninjitsu'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ninjitsu = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: magic of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_magic
static int tolua_get_FightProp_unsigned_magic(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'magic'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->magic);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: magic of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_magic
static int tolua_set_FightProp_unsigned_magic(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'magic'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->magic = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: leixlaeg of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_leixlaeg
static int tolua_get_FightProp_unsigned_leixlaeg(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'leixlaeg'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->leixlaeg);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: leixlaeg of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_leixlaeg
static int tolua_set_FightProp_unsigned_leixlaeg(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'leixlaeg'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->leixlaeg = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: curHp of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_curHp
static int tolua_get_FightProp_unsigned_curHp(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'curHp'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->curHp);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: curHp of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_curHp
static int tolua_set_FightProp_unsigned_curHp(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'curHp'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->curHp = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: initiative of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_initiative
static int tolua_get_FightProp_unsigned_initiative(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'initiative'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->initiative);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: initiative of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_initiative
static int tolua_set_FightProp_unsigned_initiative(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'initiative'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->initiative = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: hitlevel of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_hitlevel
static int tolua_get_FightProp_unsigned_hitlevel(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hitlevel'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->hitlevel);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: hitlevel of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_hitlevel
static int tolua_set_FightProp_unsigned_hitlevel(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hitlevel'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->hitlevel = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: chakra of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_chakra
static int tolua_get_FightProp_unsigned_chakra(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'chakra'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->chakra);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: chakra of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_chakra
static int tolua_set_FightProp_unsigned_chakra(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'chakra'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->chakra = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: phyattack of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_phyattack
static int tolua_get_FightProp_unsigned_phyattack(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'phyattack'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->phyattack);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: phyattack of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_phyattack
static int tolua_set_FightProp_unsigned_phyattack(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'phyattack'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->phyattack = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: magattack of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_magattack
static int tolua_get_FightProp_unsigned_magattack(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'magattack'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->magattack);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: magattack of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_magattack
static int tolua_set_FightProp_unsigned_magattack(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'magattack'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->magattack = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: phydefence of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_phydefence
static int tolua_get_FightProp_unsigned_phydefence(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'phydefence'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->phydefence);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: phydefence of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_phydefence
static int tolua_set_FightProp_unsigned_phydefence(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'phydefence'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->phydefence = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: magdefence of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_magdefence
static int tolua_get_FightProp_unsigned_magdefence(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'magdefence'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->magdefence);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: magdefence of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_magdefence
static int tolua_set_FightProp_unsigned_magdefence(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'magdefence'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->magdefence = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: skillattack of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_skillattack
static int tolua_get_FightProp_unsigned_skillattack(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skillattack'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->skillattack);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: skillattack of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_skillattack
static int tolua_set_FightProp_unsigned_skillattack(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skillattack'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->skillattack = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: skilldefence of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_skilldefence
static int tolua_get_FightProp_unsigned_skilldefence(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skilldefence'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->skilldefence);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: skilldefence of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_skilldefence
static int tolua_set_FightProp_unsigned_skilldefence(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skilldefence'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->skilldefence = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cridamlevel of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_cridamlevel
static int tolua_get_FightProp_unsigned_cridamlevel(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cridamlevel'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->cridamlevel);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cridamlevel of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_cridamlevel
static int tolua_set_FightProp_unsigned_cridamlevel(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cridamlevel'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->cridamlevel = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: hitrate of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_hitrate
static int tolua_get_FightProp_unsigned_hitrate(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hitrate'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->hitrate);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: hitrate of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_hitrate
static int tolua_set_FightProp_unsigned_hitrate(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hitrate'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->hitrate = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: dodgelevel of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_dodgelevel
static int tolua_get_FightProp_unsigned_dodgelevel(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dodgelevel'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->dodgelevel);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: dodgelevel of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_dodgelevel
static int tolua_set_FightProp_unsigned_dodgelevel(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dodgelevel'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->dodgelevel = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: dodgerate of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_dodgerate
static int tolua_get_FightProp_unsigned_dodgerate(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dodgerate'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->dodgerate);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: dodgerate of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_dodgerate
static int tolua_set_FightProp_unsigned_dodgerate(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dodgerate'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->dodgerate = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: critlevel of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_critlevel
static int tolua_get_FightProp_unsigned_critlevel(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'critlevel'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->critlevel);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: critlevel of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_critlevel
static int tolua_set_FightProp_unsigned_critlevel(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'critlevel'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->critlevel = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: crirate of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_crirate
static int tolua_get_FightProp_unsigned_crirate(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'crirate'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->crirate);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: crirate of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_crirate
static int tolua_set_FightProp_unsigned_crirate(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'crirate'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->crirate = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: resistcrilevel of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_resistcrilevel
static int tolua_get_FightProp_unsigned_resistcrilevel(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'resistcrilevel'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->resistcrilevel);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: resistcrilevel of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_resistcrilevel
static int tolua_set_FightProp_unsigned_resistcrilevel(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'resistcrilevel'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->resistcrilevel = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: resistcrirate of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_resistcrirate
static int tolua_get_FightProp_unsigned_resistcrirate(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'resistcrirate'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->resistcrirate);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: resistcrirate of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_resistcrirate
static int tolua_set_FightProp_unsigned_resistcrirate(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'resistcrirate'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->resistcrirate = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: blocklevel of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_blocklevel
static int tolua_get_FightProp_unsigned_blocklevel(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'blocklevel'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->blocklevel);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: blocklevel of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_blocklevel
static int tolua_set_FightProp_unsigned_blocklevel(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'blocklevel'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->blocklevel = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: blockratio of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_blockratio
static int tolua_get_FightProp_unsigned_blockratio(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'blockratio'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->blockratio);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: blockratio of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_blockratio
static int tolua_set_FightProp_unsigned_blockratio(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'blockratio'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->blockratio = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: wrecklevel of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_wrecklevel
static int tolua_get_FightProp_unsigned_wrecklevel(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'wrecklevel'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->wrecklevel);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: wrecklevel of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_wrecklevel
static int tolua_set_FightProp_unsigned_wrecklevel(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'wrecklevel'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->wrecklevel = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: wreckratio of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_wreckratio
static int tolua_get_FightProp_unsigned_wreckratio(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'wreckratio'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->wreckratio);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: wreckratio of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_wreckratio
static int tolua_set_FightProp_unsigned_wreckratio(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'wreckratio'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->wreckratio = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: guadefendlevel of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_guadefendlevel
static int tolua_get_FightProp_unsigned_guadefendlevel(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'guadefendlevel'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->guadefendlevel);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: guadefendlevel of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_guadefendlevel
static int tolua_set_FightProp_unsigned_guadefendlevel(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'guadefendlevel'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->guadefendlevel = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ninjitsu_educate_value of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_ninjitsu_educate_value
static int tolua_get_FightProp_ninjitsu_educate_value(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ninjitsu_educate_value'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ninjitsu_educate_value);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ninjitsu_educate_value of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_ninjitsu_educate_value
static int tolua_set_FightProp_ninjitsu_educate_value(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ninjitsu_educate_value'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ninjitsu_educate_value = ((  int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: magic_educate_value of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_magic_educate_value
static int tolua_get_FightProp_magic_educate_value(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'magic_educate_value'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->magic_educate_value);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: magic_educate_value of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_magic_educate_value
static int tolua_set_FightProp_magic_educate_value(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'magic_educate_value'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->magic_educate_value = ((  int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: leixlaeg_educate_value of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_leixlaeg_educate_value
static int tolua_get_FightProp_leixlaeg_educate_value(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'leixlaeg_educate_value'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->leixlaeg_educate_value);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: leixlaeg_educate_value of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_leixlaeg_educate_value
static int tolua_set_FightProp_leixlaeg_educate_value(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'leixlaeg_educate_value'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->leixlaeg_educate_value = ((  int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: controlAddBufRatio of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_controlAddBufRatio
static int tolua_get_FightProp_unsigned_controlAddBufRatio(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'controlAddBufRatio'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->controlAddBufRatio);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: controlAddBufRatio of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_controlAddBufRatio
static int tolua_set_FightProp_unsigned_controlAddBufRatio(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'controlAddBufRatio'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->controlAddBufRatio = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: controlResBufRatio of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_controlResBufRatio
static int tolua_get_FightProp_unsigned_controlResBufRatio(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'controlResBufRatio'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->controlResBufRatio);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: controlResBufRatio of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_controlResBufRatio
static int tolua_set_FightProp_unsigned_controlResBufRatio(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'controlResBufRatio'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->controlResBufRatio = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mark_power of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_mark_power
static int tolua_get_FightProp_unsigned_mark_power(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mark_power'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->mark_power);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mark_power of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_mark_power
static int tolua_set_FightProp_unsigned_mark_power(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mark_power'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mark_power = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: combatPower of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_get_FightProp_unsigned_combatPower
static int tolua_get_FightProp_unsigned_combatPower(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'combatPower'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->combatPower);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: combatPower of class  FightProp */
#ifndef TOLUA_DISABLE_tolua_set_FightProp_unsigned_combatPower
static int tolua_set_FightProp_unsigned_combatPower(lua_State* tolua_S)
{
  FightProp* self = (FightProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'combatPower'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->combatPower = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: level of class  PlayerPartner */
#ifndef TOLUA_DISABLE_tolua_get_PlayerPartner_unsigned_level
static int tolua_get_PlayerPartner_unsigned_level(lua_State* tolua_S)
{
  PlayerPartner* self = (PlayerPartner*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'level'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->level);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: level of class  PlayerPartner */
#ifndef TOLUA_DISABLE_tolua_set_PlayerPartner_unsigned_level
static int tolua_set_PlayerPartner_unsigned_level(lua_State* tolua_S)
{
  PlayerPartner* self = (PlayerPartner*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'level'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->level = (( unsigned short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_PhalanxId of class  PlayerPartner */
#ifndef TOLUA_DISABLE_tolua_get_PlayerPartner_unsigned_m_PhalanxId
static int tolua_get_PlayerPartner_unsigned_m_PhalanxId(lua_State* tolua_S)
{
  PlayerPartner* self = (PlayerPartner*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_PhalanxId'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_PhalanxId);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_PhalanxId of class  PlayerPartner */
#ifndef TOLUA_DISABLE_tolua_set_PlayerPartner_unsigned_m_PhalanxId
static int tolua_set_PlayerPartner_unsigned_m_PhalanxId(lua_State* tolua_S)
{
  PlayerPartner* self = (PlayerPartner*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_PhalanxId'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_PhalanxId = (( unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_curstate of class  PlayerPartner */
#ifndef TOLUA_DISABLE_tolua_get_PlayerPartner_unsigned_m_curstate
static int tolua_get_PlayerPartner_unsigned_m_curstate(lua_State* tolua_S)
{
  PlayerPartner* self = (PlayerPartner*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_curstate'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_curstate);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_curstate of class  PlayerPartner */
#ifndef TOLUA_DISABLE_tolua_set_PlayerPartner_unsigned_m_curstate
static int tolua_set_PlayerPartner_unsigned_m_curstate(lua_State* tolua_S)
{
  PlayerPartner* self = (PlayerPartner*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_curstate'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_curstate = (( unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: isMainPartner of class  PlayerPartner */
#ifndef TOLUA_DISABLE_tolua_Player_PlayerPartner_isMainPartner00
static int tolua_Player_PlayerPartner_isMainPartner00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PlayerPartner",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PlayerPartner* self = (PlayerPartner*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isMainPartner'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isMainPartner();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isMainPartner'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: havePassiveSkill of class  PlayerPartner */
#ifndef TOLUA_DISABLE_tolua_Player_PlayerPartner_havePassiveSkill00
static int tolua_Player_PlayerPartner_havePassiveSkill00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PlayerPartner",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PlayerPartner* self = (PlayerPartner*)  tolua_tousertype(tolua_S,1,0);
  unsigned int psTypeId = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
  lua_Object psTbl = ((lua_Object)  tolua_tovalue(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'havePassiveSkill'", NULL);
#endif
  {
   self->havePassiveSkill(psTypeId,psTbl);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'havePassiveSkill'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPsParam of class  PlayerPartner */
#ifndef TOLUA_DISABLE_tolua_Player_PlayerPartner_getPsParam00
static int tolua_Player_PlayerPartner_getPsParam00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PlayerPartner",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PlayerPartner* self = (PlayerPartner*)  tolua_tousertype(tolua_S,1,0);
  unsigned int psTypeId = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
  lua_Object psTbl = ((lua_Object)  tolua_tovalue(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPsParam'", NULL);
#endif
  {
   self->getPsParam(psTypeId,psTbl);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPsParam'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: isNpc of class  FightForce */
#ifndef TOLUA_DISABLE_tolua_get_FightForce_isNpc
static int tolua_get_FightForce_isNpc(lua_State* tolua_S)
{
  FightForce* self = (FightForce*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isNpc'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->isNpc);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: isNpc of class  FightForce */
#ifndef TOLUA_DISABLE_tolua_set_FightForce_isNpc
static int tolua_set_FightForce_isNpc(lua_State* tolua_S)
{
  FightForce* self = (FightForce*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isNpc'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->isNpc = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: myUnits of class  FightForce */
#ifndef TOLUA_DISABLE_tolua_get_Player_FightForce_myUnits
static int tolua_get_Player_FightForce_myUnits(lua_State* tolua_S)
{
 int tolua_index;
  FightForce* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (FightForce*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=9)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->myUnits[tolua_index],"FightUnit");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: myUnits of class  FightForce */
#ifndef TOLUA_DISABLE_tolua_set_Player_FightForce_myUnits
static int tolua_set_Player_FightForce_myUnits(lua_State* tolua_S)
{
 int tolua_index;
  FightForce* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (FightForce*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=9)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->myUnits[tolua_index] = ((FightUnit*)  tolua_tousertype(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: field of class  FightForce */
#ifndef TOLUA_DISABLE_tolua_get_FightForce_field_ptr
static int tolua_get_FightForce_field_ptr(lua_State* tolua_S)
{
  FightForce* self = (FightForce*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'field'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->field,"FightField");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: field of class  FightForce */
#ifndef TOLUA_DISABLE_tolua_set_FightForce_field_ptr
static int tolua_set_FightForce_field_ptr(lua_State* tolua_S)
{
  FightForce* self = (FightForce*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'field'",NULL);
  if (!tolua_isusertype(tolua_S,2,"FightField",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->field = ((FightField*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: initiative of class  FightForce */
#ifndef TOLUA_DISABLE_tolua_get_FightForce_unsigned_initiative
static int tolua_get_FightForce_unsigned_initiative(lua_State* tolua_S)
{
  FightForce* self = (FightForce*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'initiative'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->initiative);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: initiative of class  FightForce */
#ifndef TOLUA_DISABLE_tolua_set_FightForce_unsigned_initiative
static int tolua_set_FightForce_unsigned_initiative(lua_State* tolua_S)
{
  FightForce* self = (FightForce*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'initiative'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->initiative = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: liveNum of class  FightForce */
#ifndef TOLUA_DISABLE_tolua_get_FightForce_unsigned_liveNum
static int tolua_get_FightForce_unsigned_liveNum(lua_State* tolua_S)
{
  FightForce* self = (FightForce*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'liveNum'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->liveNum);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: liveNum of class  FightForce */
#ifndef TOLUA_DISABLE_tolua_set_FightForce_unsigned_liveNum
static int tolua_set_FightForce_unsigned_liveNum(lua_State* tolua_S)
{
  FightForce* self = (FightForce*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'liveNum'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->liveNum = (( unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: totalHp of class  FightForce */
#ifndef TOLUA_DISABLE_tolua_get_FightForce_unsigned_totalHp
static int tolua_get_FightForce_unsigned_totalHp(lua_State* tolua_S)
{
  FightForce* self = (FightForce*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'totalHp'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->totalHp);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: totalHp of class  FightForce */
#ifndef TOLUA_DISABLE_tolua_set_FightForce_unsigned_totalHp
static int tolua_set_FightForce_unsigned_totalHp(lua_State* tolua_S)
{
  FightForce* self = (FightForce*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'totalHp'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->totalHp = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: skillId of class  SkillTem */
#ifndef TOLUA_DISABLE_tolua_get_SkillTem_unsigned_skillId
static int tolua_get_SkillTem_unsigned_skillId(lua_State* tolua_S)
{
  SkillTem* self = (SkillTem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skillId'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->skillId);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: skillId of class  SkillTem */
#ifndef TOLUA_DISABLE_tolua_set_SkillTem_unsigned_skillId
static int tolua_set_SkillTem_unsigned_skillId(lua_State* tolua_S)
{
  SkillTem* self = (SkillTem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skillId'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->skillId = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: skillType of class  SkillTem */
#ifndef TOLUA_DISABLE_tolua_get_SkillTem_skillType
static int tolua_get_SkillTem_skillType(lua_State* tolua_S)
{
  SkillTem* self = (SkillTem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skillType'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->skillType);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: skillType of class  SkillTem */
#ifndef TOLUA_DISABLE_tolua_set_SkillTem_skillType
static int tolua_set_SkillTem_skillType(lua_State* tolua_S)
{
  SkillTem* self = (SkillTem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skillType'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->skillType = ((SKILLTYPE) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: at of class  SkillTem */
#ifndef TOLUA_DISABLE_tolua_get_SkillTem_at
static int tolua_get_SkillTem_at(lua_State* tolua_S)
{
  SkillTem* self = (SkillTem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'at'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->at);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: at of class  SkillTem */
#ifndef TOLUA_DISABLE_tolua_set_SkillTem_at
static int tolua_set_SkillTem_at(lua_State* tolua_S)
{
  SkillTem* self = (SkillTem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'at'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->at = ((ATTACKTYPE) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ft of class  SkillTem */
#ifndef TOLUA_DISABLE_tolua_get_SkillTem_ft
static int tolua_get_SkillTem_ft(lua_State* tolua_S)
{
  SkillTem* self = (SkillTem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ft'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ft);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ft of class  SkillTem */
#ifndef TOLUA_DISABLE_tolua_set_SkillTem_ft
static int tolua_set_SkillTem_ft(lua_State* tolua_S)
{
  SkillTem* self = (SkillTem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ft'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ft = ((FORMULATYPE) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ss of class  SkillTem */
#ifndef TOLUA_DISABLE_tolua_get_SkillTem_ss
static int tolua_get_SkillTem_ss(lua_State* tolua_S)
{
  SkillTem* self = (SkillTem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ss'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ss);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ss of class  SkillTem */
#ifndef TOLUA_DISABLE_tolua_set_SkillTem_ss
static int tolua_set_SkillTem_ss(lua_State* tolua_S)
{
  SkillTem* self = (SkillTem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ss'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ss = ((SKILL_SPAN) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tartgertypepara of class  SkillTem */
#ifndef TOLUA_DISABLE_tolua_get_SkillTem_unsigned_tartgertypepara
static int tolua_get_SkillTem_unsigned_tartgertypepara(lua_State* tolua_S)
{
  SkillTem* self = (SkillTem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tartgertypepara'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->tartgertypepara);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tartgertypepara of class  SkillTem */
#ifndef TOLUA_DISABLE_tolua_set_SkillTem_unsigned_tartgertypepara
static int tolua_set_SkillTem_unsigned_tartgertypepara(lua_State* tolua_S)
{
  SkillTem* self = (SkillTem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tartgertypepara'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tartgertypepara = (( unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: isNpc of class  FightUnit */
#ifndef TOLUA_DISABLE_tolua_get_FightUnit_isNpc
static int tolua_get_FightUnit_isNpc(lua_State* tolua_S)
{
  FightUnit* self = (FightUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isNpc'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->isNpc);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: isNpc of class  FightUnit */
#ifndef TOLUA_DISABLE_tolua_set_FightUnit_isNpc
static int tolua_set_FightUnit_isNpc(lua_State* tolua_S)
{
  FightUnit* self = (FightUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isNpc'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->isNpc = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: isAttack of class  FightUnit */
#ifndef TOLUA_DISABLE_tolua_get_FightUnit_isAttack
static int tolua_get_FightUnit_isAttack(lua_State* tolua_S)
{
  FightUnit* self = (FightUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isAttack'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->isAttack);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: isAttack of class  FightUnit */
#ifndef TOLUA_DISABLE_tolua_set_FightUnit_isAttack
static int tolua_set_FightUnit_isAttack(lua_State* tolua_S)
{
  FightUnit* self = (FightUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isAttack'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->isAttack = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: myForce of class  FightUnit */
#ifndef TOLUA_DISABLE_tolua_get_FightUnit_myForce_ptr
static int tolua_get_FightUnit_myForce_ptr(lua_State* tolua_S)
{
  FightUnit* self = (FightUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'myForce'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->myForce,"FightForce");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: myForce of class  FightUnit */
#ifndef TOLUA_DISABLE_tolua_set_FightUnit_myForce_ptr
static int tolua_set_FightUnit_myForce_ptr(lua_State* tolua_S)
{
  FightUnit* self = (FightUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'myForce'",NULL);
  if (!tolua_isusertype(tolua_S,2,"FightForce",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->myForce = ((FightForce*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pos of class  FightUnit */
#ifndef TOLUA_DISABLE_tolua_get_FightUnit_pos
static int tolua_get_FightUnit_pos(lua_State* tolua_S)
{
  FightUnit* self = (FightUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pos'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->pos);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: pos of class  FightUnit */
#ifndef TOLUA_DISABLE_tolua_set_FightUnit_pos
static int tolua_set_FightUnit_pos(lua_State* tolua_S)
{
  FightUnit* self = (FightUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pos'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->pos = ((PHALANX_POS) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxHp of class  FightUnit */
#ifndef TOLUA_DISABLE_tolua_get_FightUnit_unsigned_maxHp
static int tolua_get_FightUnit_unsigned_maxHp(lua_State* tolua_S)
{
  FightUnit* self = (FightUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxHp'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->maxHp);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxHp of class  FightUnit */
#ifndef TOLUA_DISABLE_tolua_set_FightUnit_unsigned_maxHp
static int tolua_set_FightUnit_unsigned_maxHp(lua_State* tolua_S)
{
  FightUnit* self = (FightUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxHp'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->maxHp = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: havePassiveSkill of class  FightUnit */
#ifndef TOLUA_DISABLE_tolua_Player_FightUnit_havePassiveSkill00
static int tolua_Player_FightUnit_havePassiveSkill00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightUnit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightUnit* self = (FightUnit*)  tolua_tousertype(tolua_S,1,0);
  unsigned int psTypeId = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
  lua_Object psTbl = ((lua_Object)  tolua_tovalue(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'havePassiveSkill'", NULL);
#endif
  {
   self->havePassiveSkill(psTypeId,psTbl);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'havePassiveSkill'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPsParam of class  FightUnit */
#ifndef TOLUA_DISABLE_tolua_Player_FightUnit_getPsParam00
static int tolua_Player_FightUnit_getPsParam00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightUnit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightUnit* self = (FightUnit*)  tolua_tousertype(tolua_S,1,0);
  unsigned int psTypeId = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
  lua_Object psTbl = ((lua_Object)  tolua_tovalue(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPsParam'", NULL);
#endif
  {
   self->getPsParam(psTypeId,psTbl);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPsParam'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTriggerPsCount of class  FightUnit */
#ifndef TOLUA_DISABLE_tolua_Player_FightUnit_getTriggerPsCount00
static int tolua_Player_FightUnit_getTriggerPsCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightUnit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightUnit* self = (FightUnit*)  tolua_tousertype(tolua_S,1,0);
  unsigned int psId = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTriggerPsCount'", NULL);
#endif
  {
   unsigned char tolua_ret = ( unsigned char)  self->getTriggerPsCount(psId);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTriggerPsCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTriggerPsCount of class  FightUnit */
#ifndef TOLUA_DISABLE_tolua_Player_FightUnit_setTriggerPsCount00
static int tolua_Player_FightUnit_setTriggerPsCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightUnit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightUnit* self = (FightUnit*)  tolua_tousertype(tolua_S,1,0);
  unsigned int psId = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned char triggerCount = (( unsigned char)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTriggerPsCount'", NULL);
#endif
  {
   self->setTriggerPsCount(psId,triggerCount);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTriggerPsCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFightProp of class  FightUnit */
#ifndef TOLUA_DISABLE_tolua_Player_FightUnit_getFightProp00
static int tolua_Player_FightUnit_getFightProp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightUnit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightUnit* self = (FightUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFightProp'", NULL);
#endif
  {
   FightProp* tolua_ret = (FightProp*)  self->getFightProp();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightProp");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFightProp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: attackPos of class  FightAttack */
#ifndef TOLUA_DISABLE_tolua_get_FightAttack_unsigned_attackPos
static int tolua_get_FightAttack_unsigned_attackPos(lua_State* tolua_S)
{
  FightAttack* self = (FightAttack*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'attackPos'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->attackPos);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: attackPos of class  FightAttack */
#ifndef TOLUA_DISABLE_tolua_set_FightAttack_unsigned_attackPos
static int tolua_set_FightAttack_unsigned_attackPos(lua_State* tolua_S)
{
  FightAttack* self = (FightAttack*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'attackPos'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->attackPos = (( unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: skillId of class  FightAttack */
#ifndef TOLUA_DISABLE_tolua_get_FightAttack_unsigned_skillId
static int tolua_get_FightAttack_unsigned_skillId(lua_State* tolua_S)
{
  FightAttack* self = (FightAttack*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skillId'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->skillId);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: skillId of class  FightAttack */
#ifndef TOLUA_DISABLE_tolua_set_FightAttack_unsigned_skillId
static int tolua_set_FightAttack_unsigned_skillId(lua_State* tolua_S)
{
  FightAttack* self = (FightAttack*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skillId'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->skillId = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: chakra of class  FightAttack */
#ifndef TOLUA_DISABLE_tolua_get_FightAttack_unsigned_chakra
static int tolua_get_FightAttack_unsigned_chakra(lua_State* tolua_S)
{
  FightAttack* self = (FightAttack*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'chakra'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->chakra);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: chakra of class  FightAttack */
#ifndef TOLUA_DISABLE_tolua_set_FightAttack_unsigned_chakra
static int tolua_set_FightAttack_unsigned_chakra(lua_State* tolua_S)
{
  FightAttack* self = (FightAttack*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'chakra'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->chakra = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mypos of class  VictimerInfo */
#ifndef TOLUA_DISABLE_tolua_get_VictimerInfo_unsigned_mypos
static int tolua_get_VictimerInfo_unsigned_mypos(lua_State* tolua_S)
{
  VictimerInfo* self = (VictimerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mypos'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->mypos);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mypos of class  VictimerInfo */
#ifndef TOLUA_DISABLE_tolua_set_VictimerInfo_unsigned_mypos
static int tolua_set_VictimerInfo_unsigned_mypos(lua_State* tolua_S)
{
  VictimerInfo* self = (VictimerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mypos'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mypos = (( unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ae of class  VictimerInfo */
#ifndef TOLUA_DISABLE_tolua_get_VictimerInfo_ae
static int tolua_get_VictimerInfo_ae(lua_State* tolua_S)
{
  VictimerInfo* self = (VictimerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ae'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->ae,"ATTACK_EFFECT");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ae of class  VictimerInfo */
#ifndef TOLUA_DISABLE_tolua_set_VictimerInfo_ae
static int tolua_set_VictimerInfo_ae(lua_State* tolua_S)
{
  VictimerInfo* self = (VictimerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ae'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ATTACK_EFFECT",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ae = *((ATTACK_EFFECT*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: harmValue of class  VictimerInfo */
#ifndef TOLUA_DISABLE_tolua_get_VictimerInfo_harmValue
static int tolua_get_VictimerInfo_harmValue(lua_State* tolua_S)
{
  VictimerInfo* self = (VictimerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'harmValue'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->harmValue);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: harmValue of class  VictimerInfo */
#ifndef TOLUA_DISABLE_tolua_set_VictimerInfo_harmValue
static int tolua_set_VictimerInfo_harmValue(lua_State* tolua_S)
{
  VictimerInfo* self = (VictimerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'harmValue'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->harmValue = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: modChakra of class  VictimerInfo */
#ifndef TOLUA_DISABLE_tolua_get_VictimerInfo_modChakra
static int tolua_get_VictimerInfo_modChakra(lua_State* tolua_S)
{
  VictimerInfo* self = (VictimerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'modChakra'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->modChakra);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: modChakra of class  VictimerInfo */
#ifndef TOLUA_DISABLE_tolua_set_VictimerInfo_modChakra
static int tolua_set_VictimerInfo_modChakra(lua_State* tolua_S)
{
  VictimerInfo* self = (VictimerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'modChakra'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->modChakra = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: skillId of class  VictimerInfo */
#ifndef TOLUA_DISABLE_tolua_get_VictimerInfo_unsigned_skillId
static int tolua_get_VictimerInfo_unsigned_skillId(lua_State* tolua_S)
{
  VictimerInfo* self = (VictimerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skillId'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->skillId);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: skillId of class  VictimerInfo */
#ifndef TOLUA_DISABLE_tolua_set_VictimerInfo_unsigned_skillId
static int tolua_set_VictimerInfo_unsigned_skillId(lua_State* tolua_S)
{
  VictimerInfo* self = (VictimerInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skillId'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->skillId = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: fft of class  FightField */
#ifndef TOLUA_DISABLE_tolua_get_FightField_fft
static int tolua_get_FightField_fft(lua_State* tolua_S)
{
  FightField* self = (FightField*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fft'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->fft,"FIGHT_FIELD_TYPE");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: fft of class  FightField */
#ifndef TOLUA_DISABLE_tolua_set_FightField_fft
static int tolua_set_FightField_fft(lua_State* tolua_S)
{
  FightField* self = (FightField*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fft'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"FIGHT_FIELD_TYPE",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->fft = *((FIGHT_FIELD_TYPE*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: attacher of class  FightField */
#ifndef TOLUA_DISABLE_tolua_get_FightField_attacher_ptr
static int tolua_get_FightField_attacher_ptr(lua_State* tolua_S)
{
  FightField* self = (FightField*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'attacher'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->attacher,"Player");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: attacher of class  FightField */
#ifndef TOLUA_DISABLE_tolua_set_FightField_attacher_ptr
static int tolua_set_FightField_attacher_ptr(lua_State* tolua_S)
{
  FightField* self = (FightField*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'attacher'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Player",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->attacher = ((Player*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: addBuf of class  FightField */
#ifndef TOLUA_DISABLE_tolua_Player_FightField_addBuf00
static int tolua_Player_FightField_addBuf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightField",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightUnit",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"FightUnit",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"FightAttack",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightField* self = (FightField*)  tolua_tousertype(tolua_S,1,0);
  FightUnit* pCaster = ((FightUnit*)  tolua_tousertype(tolua_S,2,0));
  FightUnit* pVictimer = ((FightUnit*)  tolua_tousertype(tolua_S,3,0));
  FightAttack* pFa = ((FightAttack*)  tolua_tousertype(tolua_S,4,0));
  unsigned int effectId = (( unsigned int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addBuf'", NULL);
#endif
  {
   self->addBuf(pCaster,pVictimer,pFa,effectId);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addBuf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addBuf of class  FightField */
#ifndef TOLUA_DISABLE_tolua_Player_FightField_addBuf01
static int tolua_Player_FightField_addBuf01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightField",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightUnit",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"FightForce",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"FightAttack",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,6,"SkillTem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  FightField* self = (FightField*)  tolua_tousertype(tolua_S,1,0);
  FightUnit* pUnit = ((FightUnit*)  tolua_tousertype(tolua_S,2,0));
  FightForce* pForce = ((FightForce*)  tolua_tousertype(tolua_S,3,0));
  FightAttack* pFa = ((FightAttack*)  tolua_tousertype(tolua_S,4,0));
  unsigned int effectId = (( unsigned int)  tolua_tonumber(tolua_S,5,0));
  SkillTem* pSkill = ((SkillTem*)  tolua_tousertype(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addBuf'", NULL);
#endif
  {
   self->addBuf(pUnit,pForce,pFa,effectId,pSkill);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Player_FightField_addBuf00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Player_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"Player","Player","",NULL);
  tolua_beginmodule(tolua_S,"Player");
   tolua_function(tolua_S,"addExp",tolua_Player_Player_addExp00);
   tolua_function(tolua_S,"createPakcet",tolua_Player_Player_createPakcet00);
   tolua_function(tolua_S,"sendPacket",tolua_Player_Player_sendPacket00);
   tolua_function(tolua_S,"toString",tolua_Player_Player_toString00);
   tolua_function(tolua_S,"rewardGift",tolua_Player_Player_rewardGift00);
   tolua_function(tolua_S,"postBulletin",tolua_Player_Player_postBulletin00);
   tolua_function(tolua_S,"deleteViewIntrest",tolua_Player_Player_deleteViewIntrest00);
   tolua_function(tolua_S,"isInViewInstrest",tolua_Player_Player_isInViewInstrest00);
   tolua_variable(tolua_S,"mainPartnerId",tolua_get_Player_unsigned_mainPartnerId,tolua_set_Player_unsigned_mainPartnerId);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Net_Packet","Net_Packet","",NULL);
  tolua_beginmodule(tolua_S,"Net_Packet");
   tolua_function(tolua_S,"read_uint8",tolua_Player_Net_Packet_read_uint800);
   tolua_function(tolua_S,"read_uint16",tolua_Player_Net_Packet_read_uint1600);
   tolua_function(tolua_S,"read_uint32",tolua_Player_Net_Packet_read_uint3200);
   tolua_function(tolua_S,"read_string",tolua_Player_Net_Packet_read_string00);
   tolua_function(tolua_S,"write_uint8",tolua_Player_Net_Packet_write_uint800);
   tolua_function(tolua_S,"write_uint16",tolua_Player_Net_Packet_write_uint1600);
   tolua_function(tolua_S,"write_uint32",tolua_Player_Net_Packet_write_uint3200);
   tolua_function(tolua_S,"write_string",tolua_Player_Net_Packet_write_string00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"onScriptActivetyChange",tolua_Player_onScriptActivetyChange00);
  tolua_function(tolua_S,"postDbReq",tolua_Player_postDbReq00);
  tolua_cclass(tolua_S,"PartnerLevelInfo","PartnerLevelInfo","",NULL);
  tolua_beginmodule(tolua_S,"PartnerLevelInfo");
   tolua_variable(tolua_S,"ninjitsu",tolua_get_PartnerLevelInfo_unsigned_ninjitsu,tolua_set_PartnerLevelInfo_unsigned_ninjitsu);
   tolua_variable(tolua_S,"magic",tolua_get_PartnerLevelInfo_unsigned_magic,tolua_set_PartnerLevelInfo_unsigned_magic);
   tolua_variable(tolua_S,"leixlaeg",tolua_get_PartnerLevelInfo_unsigned_leixlaeg,tolua_set_PartnerLevelInfo_unsigned_leixlaeg);
   tolua_variable(tolua_S,"hp",tolua_get_PartnerLevelInfo_unsigned_hp,tolua_set_PartnerLevelInfo_unsigned_hp);
   tolua_variable(tolua_S,"chakra",tolua_get_PartnerLevelInfo_unsigned_chakra,tolua_set_PartnerLevelInfo_unsigned_chakra);
   tolua_variable(tolua_S,"phyattack",tolua_get_PartnerLevelInfo_unsigned_phyattack,tolua_set_PartnerLevelInfo_unsigned_phyattack);
   tolua_variable(tolua_S,"magattack",tolua_get_PartnerLevelInfo_unsigned_magattack,tolua_set_PartnerLevelInfo_unsigned_magattack);
   tolua_variable(tolua_S,"phydefence",tolua_get_PartnerLevelInfo_unsigned_phydefence,tolua_set_PartnerLevelInfo_unsigned_phydefence);
   tolua_variable(tolua_S,"magdefence",tolua_get_PartnerLevelInfo_unsigned_magdefence,tolua_set_PartnerLevelInfo_unsigned_magdefence);
   tolua_variable(tolua_S,"skillattack",tolua_get_PartnerLevelInfo_unsigned_skillattack,tolua_set_PartnerLevelInfo_unsigned_skillattack);
   tolua_variable(tolua_S,"skilldefence",tolua_get_PartnerLevelInfo_unsigned_skilldefence,tolua_set_PartnerLevelInfo_unsigned_skilldefence);
   tolua_variable(tolua_S,"hitrate",tolua_get_PartnerLevelInfo_unsigned_hitrate,tolua_set_PartnerLevelInfo_unsigned_hitrate);
   tolua_variable(tolua_S,"dodgerate",tolua_get_PartnerLevelInfo_unsigned_dodgerate,tolua_set_PartnerLevelInfo_unsigned_dodgerate);
   tolua_variable(tolua_S,"crirate",tolua_get_PartnerLevelInfo_unsigned_crirate,tolua_set_PartnerLevelInfo_unsigned_crirate);
   tolua_variable(tolua_S,"resistcrirate",tolua_get_PartnerLevelInfo_unsigned_resistcrirate,tolua_set_PartnerLevelInfo_unsigned_resistcrirate);
   tolua_variable(tolua_S,"blockratio",tolua_get_PartnerLevelInfo_unsigned_blockratio,tolua_set_PartnerLevelInfo_unsigned_blockratio);
   tolua_variable(tolua_S,"wreckratio",tolua_get_PartnerLevelInfo_unsigned_wreckratio,tolua_set_PartnerLevelInfo_unsigned_wreckratio);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"FightProp","FightProp","",NULL);
  tolua_beginmodule(tolua_S,"FightProp");
   tolua_variable(tolua_S,"ninjitsu",tolua_get_FightProp_unsigned_ninjitsu,tolua_set_FightProp_unsigned_ninjitsu);
   tolua_variable(tolua_S,"magic",tolua_get_FightProp_unsigned_magic,tolua_set_FightProp_unsigned_magic);
   tolua_variable(tolua_S,"leixlaeg",tolua_get_FightProp_unsigned_leixlaeg,tolua_set_FightProp_unsigned_leixlaeg);
   tolua_variable(tolua_S,"curHp",tolua_get_FightProp_unsigned_curHp,tolua_set_FightProp_unsigned_curHp);
   tolua_variable(tolua_S,"initiative",tolua_get_FightProp_unsigned_initiative,tolua_set_FightProp_unsigned_initiative);
   tolua_variable(tolua_S,"hitlevel",tolua_get_FightProp_unsigned_hitlevel,tolua_set_FightProp_unsigned_hitlevel);
   tolua_variable(tolua_S,"chakra",tolua_get_FightProp_unsigned_chakra,tolua_set_FightProp_unsigned_chakra);
   tolua_variable(tolua_S,"phyattack",tolua_get_FightProp_unsigned_phyattack,tolua_set_FightProp_unsigned_phyattack);
   tolua_variable(tolua_S,"magattack",tolua_get_FightProp_unsigned_magattack,tolua_set_FightProp_unsigned_magattack);
   tolua_variable(tolua_S,"phydefence",tolua_get_FightProp_unsigned_phydefence,tolua_set_FightProp_unsigned_phydefence);
   tolua_variable(tolua_S,"magdefence",tolua_get_FightProp_unsigned_magdefence,tolua_set_FightProp_unsigned_magdefence);
   tolua_variable(tolua_S,"skillattack",tolua_get_FightProp_unsigned_skillattack,tolua_set_FightProp_unsigned_skillattack);
   tolua_variable(tolua_S,"skilldefence",tolua_get_FightProp_unsigned_skilldefence,tolua_set_FightProp_unsigned_skilldefence);
   tolua_variable(tolua_S,"cridamlevel",tolua_get_FightProp_unsigned_cridamlevel,tolua_set_FightProp_unsigned_cridamlevel);
   tolua_variable(tolua_S,"hitrate",tolua_get_FightProp_unsigned_hitrate,tolua_set_FightProp_unsigned_hitrate);
   tolua_variable(tolua_S,"dodgelevel",tolua_get_FightProp_unsigned_dodgelevel,tolua_set_FightProp_unsigned_dodgelevel);
   tolua_variable(tolua_S,"dodgerate",tolua_get_FightProp_unsigned_dodgerate,tolua_set_FightProp_unsigned_dodgerate);
   tolua_variable(tolua_S,"critlevel",tolua_get_FightProp_unsigned_critlevel,tolua_set_FightProp_unsigned_critlevel);
   tolua_variable(tolua_S,"crirate",tolua_get_FightProp_unsigned_crirate,tolua_set_FightProp_unsigned_crirate);
   tolua_variable(tolua_S,"resistcrilevel",tolua_get_FightProp_unsigned_resistcrilevel,tolua_set_FightProp_unsigned_resistcrilevel);
   tolua_variable(tolua_S,"resistcrirate",tolua_get_FightProp_unsigned_resistcrirate,tolua_set_FightProp_unsigned_resistcrirate);
   tolua_variable(tolua_S,"blocklevel",tolua_get_FightProp_unsigned_blocklevel,tolua_set_FightProp_unsigned_blocklevel);
   tolua_variable(tolua_S,"blockratio",tolua_get_FightProp_unsigned_blockratio,tolua_set_FightProp_unsigned_blockratio);
   tolua_variable(tolua_S,"wrecklevel",tolua_get_FightProp_unsigned_wrecklevel,tolua_set_FightProp_unsigned_wrecklevel);
   tolua_variable(tolua_S,"wreckratio",tolua_get_FightProp_unsigned_wreckratio,tolua_set_FightProp_unsigned_wreckratio);
   tolua_variable(tolua_S,"guadefendlevel",tolua_get_FightProp_unsigned_guadefendlevel,tolua_set_FightProp_unsigned_guadefendlevel);
   tolua_variable(tolua_S,"ninjitsu_educate_value",tolua_get_FightProp_ninjitsu_educate_value,tolua_set_FightProp_ninjitsu_educate_value);
   tolua_variable(tolua_S,"magic_educate_value",tolua_get_FightProp_magic_educate_value,tolua_set_FightProp_magic_educate_value);
   tolua_variable(tolua_S,"leixlaeg_educate_value",tolua_get_FightProp_leixlaeg_educate_value,tolua_set_FightProp_leixlaeg_educate_value);
   tolua_variable(tolua_S,"controlAddBufRatio",tolua_get_FightProp_unsigned_controlAddBufRatio,tolua_set_FightProp_unsigned_controlAddBufRatio);
   tolua_variable(tolua_S,"controlResBufRatio",tolua_get_FightProp_unsigned_controlResBufRatio,tolua_set_FightProp_unsigned_controlResBufRatio);
   tolua_variable(tolua_S,"mark_power",tolua_get_FightProp_unsigned_mark_power,tolua_set_FightProp_unsigned_mark_power);
   tolua_variable(tolua_S,"combatPower",tolua_get_FightProp_unsigned_combatPower,tolua_set_FightProp_unsigned_combatPower);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"PlayerPartner","PlayerPartner","",NULL);
  tolua_beginmodule(tolua_S,"PlayerPartner");
   tolua_variable(tolua_S,"level",tolua_get_PlayerPartner_unsigned_level,tolua_set_PlayerPartner_unsigned_level);
   tolua_variable(tolua_S,"m_PhalanxId",tolua_get_PlayerPartner_unsigned_m_PhalanxId,tolua_set_PlayerPartner_unsigned_m_PhalanxId);
   tolua_variable(tolua_S,"m_curstate",tolua_get_PlayerPartner_unsigned_m_curstate,tolua_set_PlayerPartner_unsigned_m_curstate);
   tolua_function(tolua_S,"isMainPartner",tolua_Player_PlayerPartner_isMainPartner00);
   tolua_function(tolua_S,"havePassiveSkill",tolua_Player_PlayerPartner_havePassiveSkill00);
   tolua_function(tolua_S,"getPsParam",tolua_Player_PlayerPartner_getPsParam00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"FightForce","FightForce","",NULL);
  tolua_beginmodule(tolua_S,"FightForce");
   tolua_variable(tolua_S,"isNpc",tolua_get_FightForce_isNpc,tolua_set_FightForce_isNpc);
   tolua_array(tolua_S,"myUnits",tolua_get_Player_FightForce_myUnits,tolua_set_Player_FightForce_myUnits);
   tolua_variable(tolua_S,"field",tolua_get_FightForce_field_ptr,tolua_set_FightForce_field_ptr);
   tolua_variable(tolua_S,"initiative",tolua_get_FightForce_unsigned_initiative,tolua_set_FightForce_unsigned_initiative);
   tolua_variable(tolua_S,"liveNum",tolua_get_FightForce_unsigned_liveNum,tolua_set_FightForce_unsigned_liveNum);
   tolua_variable(tolua_S,"totalHp",tolua_get_FightForce_unsigned_totalHp,tolua_set_FightForce_unsigned_totalHp);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"ST_HARM",ST_HARM);
  tolua_constant(tolua_S,"ST_EFFECT",ST_EFFECT);
  tolua_constant(tolua_S,"AT_COMMON",AT_COMMON);
  tolua_constant(tolua_S,"AT_SKILL",AT_SKILL);
  tolua_constant(tolua_S,"SS_SINGLE",SS_SINGLE);
  tolua_constant(tolua_S,"SS_ROW",SS_ROW);
  tolua_constant(tolua_S,"SS_COLUMN",SS_COLUMN);
  tolua_constant(tolua_S,"SS_ALL",SS_ALL);
  tolua_constant(tolua_S,"SS_MINHP",SS_MINHP);
  tolua_constant(tolua_S,"SS_MAXNINJITSU",SS_MAXNINJITSU);
  tolua_constant(tolua_S,"SS_COMMATTACKLAST",SS_COMMATTACKLAST);
  tolua_constant(tolua_S,"SS_MINHPPARTNERS",SS_MINHPPARTNERS);
  tolua_constant(tolua_S,"SS_ROWLAST",SS_ROWLAST);
  tolua_constant(tolua_S,"FT_PHYHARM",FT_PHYHARM);
  tolua_constant(tolua_S,"FT_MAGICHARM",FT_MAGICHARM);
  tolua_cclass(tolua_S,"SkillTem","SkillTem","",NULL);
  tolua_beginmodule(tolua_S,"SkillTem");
   tolua_variable(tolua_S,"skillId",tolua_get_SkillTem_unsigned_skillId,tolua_set_SkillTem_unsigned_skillId);
   tolua_variable(tolua_S,"skillType",tolua_get_SkillTem_skillType,tolua_set_SkillTem_skillType);
   tolua_variable(tolua_S,"at",tolua_get_SkillTem_at,tolua_set_SkillTem_at);
   tolua_variable(tolua_S,"ft",tolua_get_SkillTem_ft,tolua_set_SkillTem_ft);
   tolua_variable(tolua_S,"ss",tolua_get_SkillTem_ss,tolua_set_SkillTem_ss);
   tolua_variable(tolua_S,"tartgertypepara",tolua_get_SkillTem_unsigned_tartgertypepara,tolua_set_SkillTem_unsigned_tartgertypepara);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"RIGHT_TOP",RIGHT_TOP);
  tolua_constant(tolua_S,"RIGHT_CENTER",RIGHT_CENTER);
  tolua_constant(tolua_S,"RIGHT_BOTTOM",RIGHT_BOTTOM);
  tolua_constant(tolua_S,"CENTER_TOP",CENTER_TOP);
  tolua_constant(tolua_S,"CENTER_CENTER",CENTER_CENTER);
  tolua_constant(tolua_S,"CENTER_BOTTOM",CENTER_BOTTOM);
  tolua_constant(tolua_S,"LEFT_TOP",LEFT_TOP);
  tolua_constant(tolua_S,"LEFT_CENTER",LEFT_CENTER);
  tolua_constant(tolua_S,"LEFT_BOTTOM",LEFT_BOTTOM);
  tolua_constant(tolua_S,"PHALANX_POS_MAX",PHALANX_POS_MAX);
  tolua_cclass(tolua_S,"FightUnit","FightUnit","",NULL);
  tolua_beginmodule(tolua_S,"FightUnit");
   tolua_variable(tolua_S,"isNpc",tolua_get_FightUnit_isNpc,tolua_set_FightUnit_isNpc);
   tolua_variable(tolua_S,"isAttack",tolua_get_FightUnit_isAttack,tolua_set_FightUnit_isAttack);
   tolua_variable(tolua_S,"myForce",tolua_get_FightUnit_myForce_ptr,tolua_set_FightUnit_myForce_ptr);
   tolua_variable(tolua_S,"pos",tolua_get_FightUnit_pos,tolua_set_FightUnit_pos);
   tolua_variable(tolua_S,"maxHp",tolua_get_FightUnit_unsigned_maxHp,tolua_set_FightUnit_unsigned_maxHp);
   tolua_function(tolua_S,"havePassiveSkill",tolua_Player_FightUnit_havePassiveSkill00);
   tolua_function(tolua_S,"getPsParam",tolua_Player_FightUnit_getPsParam00);
   tolua_function(tolua_S,"getTriggerPsCount",tolua_Player_FightUnit_getTriggerPsCount00);
   tolua_function(tolua_S,"setTriggerPsCount",tolua_Player_FightUnit_setTriggerPsCount00);
   tolua_function(tolua_S,"getFightProp",tolua_Player_FightUnit_getFightProp00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"FightAttack","FightAttack","",NULL);
  tolua_beginmodule(tolua_S,"FightAttack");
   tolua_variable(tolua_S,"attackPos",tolua_get_FightAttack_unsigned_attackPos,tolua_set_FightAttack_unsigned_attackPos);
   tolua_variable(tolua_S,"skillId",tolua_get_FightAttack_unsigned_skillId,tolua_set_FightAttack_unsigned_skillId);
   tolua_variable(tolua_S,"chakra",tolua_get_FightAttack_unsigned_chakra,tolua_set_FightAttack_unsigned_chakra);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"VictimerInfo","VictimerInfo","",NULL);
  tolua_beginmodule(tolua_S,"VictimerInfo");
   tolua_variable(tolua_S,"mypos",tolua_get_VictimerInfo_unsigned_mypos,tolua_set_VictimerInfo_unsigned_mypos);
   tolua_variable(tolua_S,"ae",tolua_get_VictimerInfo_ae,tolua_set_VictimerInfo_ae);
   tolua_variable(tolua_S,"harmValue",tolua_get_VictimerInfo_harmValue,tolua_set_VictimerInfo_harmValue);
   tolua_variable(tolua_S,"modChakra",tolua_get_VictimerInfo_modChakra,tolua_set_VictimerInfo_modChakra);
   tolua_variable(tolua_S,"skillId",tolua_get_VictimerInfo_unsigned_skillId,tolua_set_VictimerInfo_unsigned_skillId);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"FightField","FightField","",NULL);
  tolua_beginmodule(tolua_S,"FightField");
   tolua_variable(tolua_S,"fft",tolua_get_FightField_fft,tolua_set_FightField_fft);
   tolua_variable(tolua_S,"attacher",tolua_get_FightField_attacher_ptr,tolua_set_FightField_attacher_ptr);
   tolua_function(tolua_S,"addBuf",tolua_Player_FightField_addBuf00);
   tolua_function(tolua_S,"addBuf",tolua_Player_FightField_addBuf01);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Player (lua_State* tolua_S) {
 return tolua_Player_open(tolua_S);
};
#endif

