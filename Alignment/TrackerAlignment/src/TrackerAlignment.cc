// Conditions database
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CondCore/DBOutputService/interface/PoolDBOutputService.h"

// Alignment
#include "CondFormats/Alignment/interface/Alignments.h"
#include "CondFormats/Alignment/interface/AlignmentErrors.h"
#include "CondFormats/Alignment/interface/AlignmentSorter.h"

#include "Alignment/TrackerAlignment/interface/TrackerAlignment.h"

//__________________________________________________________________
//
TrackerAlignment::TrackerAlignment():
  theAlignRecordName( "TrackerAlignmentRcd" ),
  theErrorRecordName( "TrackerAlignmentErrorRcd" )
{
  theAlignableTracker = new AlignableTracker;
}


//__________________________________________________________________
//
TrackerAlignment::~TrackerAlignment( void )
{

  delete theAlignableTracker;

}


//__________________________________________________________________
//
void TrackerAlignment::moveAlignablePixelEndCaps( int rawid , const align::Scalars& local_displacements,  const align::Scalars& local_rotations  ){
	
	// Displace and rotate pixelEndCaps
	const align::Alignables& thePixelEndCapsAlignables = theAlignableTracker->pixelEndcapGeomDets();
	for ( align::Alignables::const_iterator iter = thePixelEndCapsAlignables.begin(); 
          iter != thePixelEndCapsAlignables.end(); ++iter )
      { 
        
		// Get the raw ID of the associated GeomDet
		int id = (*iter)->geomDetId().rawId();
		
		// Select the given module
		if ( id == rawid ){
          
          // Convert local to global diplacements
          align::LocalVector lvector( local_displacements.at(0), local_displacements.at(1), local_displacements.at(2)); 
          align::GlobalVector gvector = ((*iter)->surface()).toGlobal( lvector );
          
          // global displacement 
          (*iter)->move( gvector );
          
          // local rotation 
          (*iter)->rotateAroundLocalX( local_rotations.at(0) ); // Local X axis rotation
          (*iter)->rotateAroundLocalY( local_rotations.at(1) ); // Local Y axis rotation
          (*iter)->rotateAroundLocalZ( local_rotations.at(2) ); // Local Z axis rotation
          
		}
      }
}
//__________________________________________________________________
//
void TrackerAlignment::moveAlignableEndCaps( int rawid , const align::Scalars& local_displacements,  const align::Scalars& local_rotations  ){
	
	// Displace and rotate EndCaps
	const align::Alignables& theEndCapsAlignables = theAlignableTracker->endcapGeomDets();
	for ( align::Alignables::const_iterator iter = theEndCapsAlignables.begin(); 
          iter != theEndCapsAlignables.end(); ++iter ){ 
		
		// Get the raw ID of the associated GeomDet
		int id = (*iter)->geomDetId().rawId();
		
		// Select the given module
		if ( id == rawid ){
			
			// Convert local to global diplacements
			align::LocalVector lvector( local_displacements.at(0), local_displacements.at(1), local_displacements.at(2)); 
			align::GlobalVector gvector = ((*iter)->surface()).toGlobal( lvector );
			
			// global displacement 
			(*iter)->move( gvector );
			
			// local rotation 
			(*iter)->rotateAroundLocalX( local_rotations.at(0) ); // Local X axis rotation
			(*iter)->rotateAroundLocalY( local_rotations.at(1) ); // Local Y axis rotation
			(*iter)->rotateAroundLocalZ( local_rotations.at(2) ); // Local Z axis rotation
			
		}
	}
}
//__________________________________________________________________
//
void TrackerAlignment::moveAlignablePixelHalfBarrels( int rawid , const align::Scalars& local_displacements,  const align::Scalars& local_rotations  ){
	
	// Displace and rotate PixelHalfBarrels
	const align::Alignables& thePixelHalfBarrelsAlignables = theAlignableTracker->pixelHalfBarrelGeomDets();
	for ( align::Alignables::const_iterator iter = thePixelHalfBarrelsAlignables.begin(); 
          iter != thePixelHalfBarrelsAlignables.end(); ++iter ){ 
		
		// Get the raw ID of the associated GeomDet
		int id = (*iter)->geomDetId().rawId();
		
		// Select the given module
		if ( id == rawid ){
			
			// Convert local to global diplacements
			align::LocalVector lvector( local_displacements.at(0), local_displacements.at(1), local_displacements.at(2)); 
			align::GlobalVector gvector = ((*iter)->surface()).toGlobal( lvector );
			
			// global displacement 
			(*iter)->move( gvector );
			
			// local rotation 
			(*iter)->rotateAroundLocalX( local_rotations.at(0) ); // Local X axis rotation
			(*iter)->rotateAroundLocalY( local_rotations.at(1) ); // Local Y axis rotation
			(*iter)->rotateAroundLocalZ( local_rotations.at(2) ); // Local Z axis rotation
			
		}
	}
}
//__________________________________________________________________
//
void TrackerAlignment::moveAlignableOuterHalfBarrels( int rawid , const align::Scalars& local_displacements,  const align::Scalars& local_rotations  ){
	
	// Displace and rotate OuterHalfBarrels
	const align::Alignables& theOuterHalfBarrelsAlignables = theAlignableTracker->outerBarrelGeomDets();
	for ( align::Alignables::const_iterator iter = theOuterHalfBarrelsAlignables.begin(); 
          iter != theOuterHalfBarrelsAlignables.end(); ++iter ){ 
		
		// Get the raw ID of the associated GeomDet
		int id = (*iter)->geomDetId().rawId();
		
		// Select the given module
		if ( id == rawid ){
			
			// Convert local to global diplacements
			align::LocalVector lvector( local_displacements.at(0), local_displacements.at(1), local_displacements.at(2)); 
			align::GlobalVector gvector = ((*iter)->surface()).toGlobal( lvector );
			
			// global displacement 
			(*iter)->move( gvector );
			
			// local rotation 
			(*iter)->rotateAroundLocalX( local_rotations.at(0) ); // Local X axis rotation
			(*iter)->rotateAroundLocalY( local_rotations.at(1) ); // Local Y axis rotation
			(*iter)->rotateAroundLocalZ( local_rotations.at(2) ); // Local Z axis rotation
			
		}
	}
}
//__________________________________________________________________
//
void TrackerAlignment::moveAlignableInnerHalfBarrels( int rawid , const align::Scalars& local_displacements,  const align::Scalars& local_rotations  ){
	
	// Displace and rotate InnerHalfBarrels
	const align::Alignables& theInnerHalfBarrelsAlignables = theAlignableTracker->innerBarrelGeomDets();
	for ( align::Alignables::const_iterator iter = theInnerHalfBarrelsAlignables.begin(); 
          iter != theInnerHalfBarrelsAlignables.end(); ++iter ){ 
		
		// Get the raw ID of the associated GeomDet
		int id = (*iter)->geomDetId().rawId();
		
		// Select the given module
		if ( id == rawid ){
			
			// Convert local to global diplacements
			align::LocalVector lvector( local_displacements.at(0), local_displacements.at(1), local_displacements.at(2)); 
			align::GlobalVector gvector = ((*iter)->surface()).toGlobal( lvector );
			
			// global displacement 
			(*iter)->move( gvector );
			
			// local rotation 
			(*iter)->rotateAroundLocalX( local_rotations.at(0) ); // Local X axis rotation
			(*iter)->rotateAroundLocalY( local_rotations.at(1) ); // Local Y axis rotation
			(*iter)->rotateAroundLocalZ( local_rotations.at(2) ); // Local Z axis rotation
			
		}
	}
}
//__________________________________________________________________
//
void TrackerAlignment::moveAlignableTIDs( int rawid , const align::Scalars& local_displacements,  const align::Scalars& local_rotations  ){
	
	// Displace and rotate TIDs
	const align::Alignables& theTIDsAlignables = theAlignableTracker->TIDGeomDets();
	for ( align::Alignables::const_iterator iter = theTIDsAlignables.begin(); 
          iter != theTIDsAlignables.end(); ++iter ){ 
		
		// Get the raw ID of the associated GeomDet
		int id = (*iter)->geomDetId().rawId();
		
		// Select the given module
		if ( id == rawid ){
			
			// Convert local to global diplacements
			align::LocalVector lvector( local_displacements.at(0), local_displacements.at(1), local_displacements.at(2)); 
			align::GlobalVector gvector = ((*iter)->surface()).toGlobal( lvector );
			
			// global displacement 
			(*iter)->move( gvector );
			
			// local rotation 
			(*iter)->rotateAroundLocalX( local_rotations.at(0) ); // Local X axis rotation
			(*iter)->rotateAroundLocalY( local_rotations.at(1) ); // Local Y axis rotation
			(*iter)->rotateAroundLocalZ( local_rotations.at(2) ); // Local Z axis rotation
			
		}
	}
}

//__________________________________________________________________
//
void TrackerAlignment::moveAlignableTIBTIDs( int rawId, const align::Scalars& globalDisplacements, const align::RotationType& backwardRotation, const align::RotationType& forwardRotation, bool toAndFro ){

        // Displace and rotate TIB and TID
	const align::Alignables& theTIBTIDAlignables = theAlignableTracker->TIBTIDGeomDets();
	for ( align::Alignables::const_iterator iter = theTIBTIDAlignables.begin(); 
          iter != theTIBTIDAlignables.end(); ++iter )
	  { 
	    
	    // Get the raw ID of the associated GeomDet
	    int id = (*iter)->geomDetId().rawId();
	    
	    // Select the given module
	    if ( id == rawId ){
	      
	      // global displacement 
	      align::GlobalVector gvector (globalDisplacements.at(0), globalDisplacements.at(1), globalDisplacements.at(2));
	      (*iter)->move( gvector );
	      
	      // global rotation
              if (toAndFro) { 
                align::RotationType theResultRotation = backwardRotation*forwardRotation.transposed();
                (*iter)->rotateInGlobalFrame( theResultRotation ); 
	      } else {
		(*iter)->rotateInGlobalFrame( backwardRotation );
	      }
	    }
      }
}


//__________________________________________________________________
//
void TrackerAlignment::saveToDB(void){
	
	// Output POOL-ORA objects
  edm::Service<cond::service::PoolDBOutputService> poolDbService;
  if( !poolDbService.isAvailable() ) // Die if not available
	throw cms::Exception("NotAvailable") << "PoolDBOutputService not available";

  // Retrieve and store
  Alignments* alignments = theAlignableTracker->alignments();
  AlignmentErrors* alignmentErrors = theAlignableTracker->alignmentErrors();


  if ( poolDbService->isNewTagRequest(theAlignRecordName) )
    poolDbService->createNewIOV<Alignments>( alignments, poolDbService->endOfTime(), 
                                             theAlignRecordName );
  else
    poolDbService->appendSinceTime<Alignments>( alignments, poolDbService->currentTime(), 
                                                theAlignRecordName );
  if ( poolDbService->isNewTagRequest(theErrorRecordName) )
    poolDbService->createNewIOV<AlignmentErrors>( alignmentErrors,
                                                  poolDbService->endOfTime(), 
                                                  theErrorRecordName );
  else
    poolDbService->appendSinceTime<AlignmentErrors>( alignmentErrors,
                                                     poolDbService->currentTime(), 
                                                     theErrorRecordName );

}

