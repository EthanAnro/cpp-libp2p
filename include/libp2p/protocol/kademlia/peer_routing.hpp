/**
 * Copyright Quadrivium LLC
 * All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <libp2p/protocol/kademlia/common.hpp>

namespace libp2p::protocol::kademlia {

  // PeerRouting is a way to find information about certain peers.
  //
  // This can be implemented by a simple lookup table, a tracking server,
  // or even a DHT (like herein).
  class PeerRouting {
   public:
    virtual ~PeerRouting() = default;

    virtual void addPeer(const PeerInfo &peer_info,
                         bool permanent,
                         bool is_connected = false) = 0;

    /// Searches for a peer with given @param ID, @returns PeerInfo
    /// with relevant addresses.
    virtual outcome::result<void> findPeer(const PeerId &peer_id,
                                           FoundPeerInfoHandler handler) = 0;

    /// Random walk step. Calls `findPeer` with random bytes as key.
    virtual outcome::result<void> findRandomPeer() = 0;
  };

}  // namespace libp2p::protocol::kademlia
