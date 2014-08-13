//
//  CMAClient.h
//  ManagementSDK
//
//  Created by Boris Bügling on 14/07/14.
//  Copyright (c) 2014 Boris Bügling. All rights reserved.
//

#import <ContentfulDeliveryAPI/ContentfulDeliveryAPI.h>

@class CMAAsset;
@class CMAContentType;
@class CMAEntry;
@class CMALocale;
@class CMAOrganization;
@class CMASpace;

typedef void(^CMAAssetFetchedBlock)(CDAResponse* response, CMAAsset* asset);
typedef void(^CMAContentTypeFetchedBlock)(CDAResponse* response, CMAContentType* contentType);
typedef void(^CMAEntryFetchedBlock)(CDAResponse* response, CMAEntry* entry);
typedef void(^CMALocaleFetchedBlock)(CDAResponse* response, CMALocale* locale);
typedef void(^CMASpaceFetchedBlock)(CDAResponse* response, CMASpace* space);

/**
 *  The CMAClient is used to request information from the server. Contrary to the delivery API,
 *  a client is not associated with one space, but with one user.
 */
@interface CMAClient : NSObject

/**
 *  Initialize a new client for requesting information from the server.
 *
 *  Access tokens can be obtained [from here](https://www.contentful.com/developers/documentation/content-management-api/#getting-started).
 *
 *  @param accessToken The access token for a given user account.
 *
 *  @return A new initialized client instance.
 */
-(id)initWithAccessToken:(NSString*)accessToken;

/**
 *  Create a new space on Contentful, in the user default organization.
 *
 *  @param name    The name of the new space.
 *  @param success Called if creation succeeds.
 *  @param failure Called if creation fails.
 *
 *  @return The request used for creation.
 */
-(CDARequest*)createSpaceWithName:(NSString*)name
                          success:(CMASpaceFetchedBlock)success
                          failure:(CDARequestFailureBlock)failure;

/**
 *  Create a new space on Contentful, in the given organization.
 *
 *  @param name         The name of the new space.
 *  @param organization The organization to create the space in.
 *  @param success      Called if creation succeeds.
 *  @param failure      Called if creation fails.
 *
 *  @return The request used for creation.
 */
-(CDARequest*)createSpaceWithName:(NSString*)name
                   inOrganization:(CMAOrganization*)organization
                          success:(CMASpaceFetchedBlock)success
                          failure:(CDARequestFailureBlock)failure;

/**
 *  Fetch all spaces the user has access to.
 *
 *  @param success Called if fetching succeeds.
 *  @param failure Called if fetching fails.
 *
 *  @return The request used for fetching data.
 */
-(CDARequest*)fetchAllSpacesWithSuccess:(CDAArrayFetchedBlock)success
                                failure:(CDARequestFailureBlock)failure;

/**
 *  Fetch all organizations the user is member of.
 *
 *  @param success Called if fetching succeeds.
 *  @param failure Called if fetching fails.
 *
 *  @return The request used for fetching data.
 */
-(CDARequest*)fetchOrganizationsWithSuccess:(CDAArrayFetchedBlock)success
                                    failure:(CDARequestFailureBlock)failure;

/**
 *  Fetch a specific space by identifier.
 *
 *  @param identifier The identifier of the space to fetch.
 *  @param success    Called if fetching succeeds.
 *  @param failure    Called if fetching fails.
 *
 *  @return The request used for fetching data.
 */
-(CDARequest*)fetchSpaceWithIdentifier:(NSString*)identifier
                               success:(CMASpaceFetchedBlock)success
                               failure:(CDARequestFailureBlock)failure;

@end
