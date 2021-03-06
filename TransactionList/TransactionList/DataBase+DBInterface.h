//
//  DataBase+DBInterface.h
//  TransactionList
//
//  Created by NowOrNever on 19/09/2017.
//  Copyright © 2017 NowOrNever. All rights reserved.
//

#import "DataBase.h"
@class User;
@class Task;
@class Message;
@interface DataBase (DBInterface)

#pragma mark -- 用户操作接口
//添加用户
- (BOOL)addUser:(User *)user;
//查找用户
- (NSArray *)findUser:(NSString *)userAccount;
- (NSArray *)getUserNameBy:(int)userId;
- (void)lookUsers;
//删除用户
- (BOOL)deleteUser:(User *)user;
//更新用户,只开放修改用户密码，电话，头像
- (BOOL)updateUserWithTel:(NSString *)userTel userId:(int)userId;
- (BOOL)updateUserWithIcon:(NSString *)userIcon userId:(int)userId;
- (BOOL)updateUserWithPassword:(NSString *)userPassword userId:(int)userId;

#pragma mark -- 联系人操作接口
//返回一个用户的所有联系人
- (NSArray *)getAllContractByUser:(int)userId;
//添加联系人
- (BOOL)addContract:(int)contractId to:(int)userId;
//删除联系人
- (BOOL)deleteContract:(int)contractId from:(int)userId;
//根据电话号码搜索联系人
- (NSArray *)searchContractByTel:(NSString *)tel;

#pragma mark -- 任务操作接口
- (BOOL)addTask:(Task *)task;
- (NSArray *)getUndoTaskDataBy:(int)userId;
- (NSArray *)getDidTaskDataBy:(int)userId;
- (BOOL)finishTask:(int)taskId;
#pragma mark -- 消息操作接口
- (BOOL)applyContractWith:(Message *)msg to:(int)contractId;

- (NSArray *)getUndoMessageByUserId:(int)userId;
@end
