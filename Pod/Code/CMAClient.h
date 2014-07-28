//
//  CMAClient.h
//  ManagementSDK
//
//  Created by Boris Bügling on 14/07/14.
//  Copyright (c) 2014 Boris Bügling. All rights reserved.
//

#import <ContentfulDeliveryAPI/ContentfulDeliveryAPI.h>

@class CMAEntry;
@class CMASpace;

typedef void(^CMAEntryFetchedBlock)(CDAResponse* response, CMAEntry* entry);
typedef void(^CMASpaceFetchedBlock)(CDAResponse* response, CMASpace* space);

@interface CMAClient : NSObject

-(id)initWithAccessToken:(NSString*)accessToken;

-(CDARequest*)fetchAllSpacesWithSuccess:(CDAArrayFetchedBlock)success
                                failure:(CDARequestFailureBlock)failure;

-(CDARequest*)fetchSpaceWithIdentifier:(NSString*)identifier
                               success:(CMASpaceFetchedBlock)success
                               failure:(CDARequestFailureBlock)failure;

@end
