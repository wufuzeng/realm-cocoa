////////////////////////////////////////////////////////////////////////////
//
// Copyright 2020 Realm Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
////////////////////////////////////////////////////////////////////////////

#import <Foundation/Foundation.h>
#import "RLMObjectId.h"

NS_ASSUME_NONNULL_BEGIN
@protocol RLMBSON;

@class RLMApp, RLMFindOptions, RLMFindOneAndModifyOptions;

@interface RLMMongoCollection : NSObject

typedef void(^RLMInsertBlock)(RLMObjectId * _Nullable, NSError * _Nullable);
typedef void(^RLMFindBlock)(NSArray<id<RLMBSON>> * _Nullable, NSError * _Nullable);

@property (nonatomic, readonly) NSString *name;

- (void)insertOneDocument:(id<RLMBSON>)document
               completion:(RLMInsertBlock)completion;

- (void)find:(id<RLMBSON>)document
     options:(RLMFindOptions *)options
  completion:(RLMFindBlock)completion;

@end

NS_ASSUME_NONNULL_END
