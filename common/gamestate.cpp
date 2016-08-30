#include "gamestate.hpp"

#include "bid.hpp"

#include <cassert>

namespace QTacitGame
{

	GameState::GameState(const GameMap& map, const std::size_t number_of_players)
		: m_map(map)
		, m_number_of_players(number_of_players)
		, m_current_bids(map.numberOfStates())
	{
		std::fill(begin(m_current_bids), end(m_current_bids), CurrentBid{0, 0});
	}

	std::size_t GameState::numberOfPlayers() const { return m_number_of_players; }

	void GameState::resolve(const std::vector<Bid>& bids)
	{
		assert(bids.size() == m_number_of_players);
		for(std::size_t i = 0; i < bids.size(); i++)
		{
			for(const auto& b : bids[i])
			{
				if(b.second > 0)
				{
					m_current_bids[b.first].player_id = i;
					m_current_bids[b.first].number_of_tokens += b.second;
				}
			}
		}
		resolveCollisions();
	}

	auto GameState::currentBids() const -> CurrentBidsContainer_t { return m_current_bids; }

	void GameState::resolveCollisions() {}

} // QTacitGame
