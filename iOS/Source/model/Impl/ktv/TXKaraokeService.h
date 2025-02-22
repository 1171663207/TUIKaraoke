//
//  TXKaraokeService.h
//  TRTCKaraokeOCDemo
//
//  Created by abyyxwang on 2020/7/1.
//  Copyright © 2020 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TXKaraokeBaseDef.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ITXRoomServiceDelegate <NSObject>

- (void)onRoomDestroyWithRoomId:(NSString *)roomID;
- (void)onRoomRecvRoomTextMsg:(NSString *)roomID message:(NSString *)message userInfo:(TXKaraokeUserInfo *)userInfo;
- (void)onRoomRecvRoomCustomMsg:(NSString *)roomID cmd:(NSString *)cmd message:(NSString *)message userInfo:(TXKaraokeUserInfo *)userInfo;
- (void)onRoomInfoChange:(TXKaraokeRoomInfo *)roomInfo;
- (void)onSeatInfoListChange:(NSArray<TXKaraokeSeatInfo *> *)seatInfoList;
- (void)onRoomAudienceEnter:(TXKaraokeUserInfo *)userInfo;
- (void)onRoomAudienceLeave:(TXKaraokeUserInfo *)userInfo;
- (void)onSeatTakeWithIndex:(NSInteger)index userInfo:(TXKaraokeUserInfo *)userInfo;
- (void)onSeatCloseWithIndex:(NSInteger)index isClose:(BOOL)isClose;
- (void)onSeatLeaveWithIndex:(NSInteger)index userInfo:(TXKaraokeUserInfo *)userInfo;
- (void)onSeatMuteWithIndex:(NSInteger)index mute:(BOOL)isMute;
- (void)onReceiveNewInvitationWithIdentifier:(NSString *)identifier inviter:(NSString *)inviter cmd:(NSString *)cmd content:(NSString *)content;
- (void)onInviteeAcceptedWithIdentifier:(NSString *)identifier invitee:(NSString *)invitee;
- (void)onInviteeRejectedWithIdentifier:(NSString *)identifier invitee:(NSString *)invitee;
- (void)onInviteeCancelledWithIdentifier:(NSString *)identifier invitee:(NSString *)invitee;
- (void)onReceiveInstructionMsg:(NSString *)instruction;
@end

static int gKaraoke_SERVICE_CODE_ERROR = -1;

@interface TXKaraokeService : NSObject

@property (nonatomic, weak) id<ITXRoomServiceDelegate> delegate;
@property (nonatomic, assign, readonly)BOOL isOwner;
@property (nonatomic, strong) NSString *ownerUserId;

+ (instancetype)sharedInstance;

- (void)loginWithSdkAppId:(int)sdkAppId userId:(NSString *)userId userSig:(NSString *)userSig callback:(TXKaraokeCallback _Nullable)callback;
- (void)logout:(TXKaraokeCallback _Nullable)callback;
- (void)getSelfInfo;
- (void)setSelfProfileWithUserName:(NSString *)userName
                         avatarUrl:(NSString *)avatarUrl
                          callback:(TXKaraokeCallback _Nullable)callback;

- (void)createRoomWithRoomId:(NSString *)roomId
                    roomName:(NSString *)roomName
                    coverUrl:(NSString *)coverUrl
                 needRequest:(BOOL)needRequest
                seatInfoList:(NSArray<TXKaraokeSeatInfo *> *)seatInfoList
                    callback:(TXKaraokeCallback _Nullable)callback;

- (void)destroyRoom:(TXKaraokeCallback _Nullable)callback;

- (void)enterRoom:(NSString *)roomId callback:(TXKaraokeCallback _Nullable)callback;
- (void)exitRoom:(TXKaraokeCallback _Nullable)callback;
- (void)takeSeat:(NSInteger)seatIndex callback:(TXKaraokeCallback _Nullable)callback;
- (void)leaveSeat:(NSInteger)seatIndex callback:(TXKaraokeCallback _Nullable)callback;
- (void)pickSeat:(NSInteger)seatIndex userId:(NSString *)userId callback:(TXKaraokeCallback _Nullable)callback;
- (void)kickSeat:(NSInteger)seatIndex callback:(TXKaraokeCallback _Nullable)callback;
- (void)muteSeat:(NSInteger)seatIndex mute:(BOOL)mute callback:(TXKaraokeCallback _Nullable)callback;
- (void)closeSeat:(NSInteger)seatIndex isClose:(BOOL)isClose callback:(TXKaraokeCallback _Nullable)callback;
- (void)getUserInfo:(NSArray<NSString *> *)userList callback:(TXKaraokeUserListCallback _Nullable)callback;
- (void)sendRoomTextMsg:(NSString *)msg callback:(TXKaraokeCallback _Nullable)callback;
- (void)sendRoomCustomMsg:(NSString *)cmd message:(NSString *)message callback:(TXKaraokeCallback _Nullable)callback;
- (void)sendGroupMsg:(NSString *)message callback:(TXKaraokeCallback _Nullable)callback;
- (void)sendInstructionMsg:(NSString *)instruction callback:(TXKaraokeCallback _Nullable)callback;
- (void)getAudienceList:(TXKaraokeUserListCallback _Nullable)callback;
- (void)getRoomInfoList:(NSArray<NSString *> *)roomIds calback:(TXKaraokeRoomInfoListCallback _Nullable)callback;
- (void)destroy;
- (NSString *)sendInvitation:(NSString *)cmd userId:(NSString *)userId content:(NSString *)content callback:(TXKaraokeCallback _Nullable)callback;
- (void)acceptInvitation:(NSString *)identifier callback:(TXKaraokeCallback _Nullable)callback;
- (void)rejectInvitaiton:(NSString *)identifier callback:(TXKaraokeCallback _Nullable)callback;
- (void)cancelInvitation:(NSString *)identifier callback:(TXKaraokeCallback _Nullable)callback;

@end

NS_ASSUME_NONNULL_END
