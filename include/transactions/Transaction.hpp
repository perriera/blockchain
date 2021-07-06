#ifndef _TRANSACTION_HPP
#define _TRANSACTION_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"

/**
 * @brief Financial Transaction
 *
 * A financial transaction is an agreement, or communication, carried out
 * between a buyer and a seller to exchange an asset for payment.
 *
 * It involves a change in the status of the finances of two or more
 * businesses or individuals. The buyer and seller are separate entities
 * or objects, often involving the exchange of items of value, such as
 * information, goods, services, and money. It is still a transaction
 * if the goods are exchanged at one time, and the money at another.
 * This is known as a two-part transaction: part one is giving the money,
 * part two is receiving the goods.
 *
 * A financial transaction always involves one or more financial asset.
 * Either buyer or seller can initiates such a transaction, hence one
 * is the originator/initiator and the other is the responder. From
 * liquidity point of view, one is the liquidity provider, the other
 * party is the liquidity consumer. The liquidity provider is also
 * called offer and the liquidity consumer is also called taker. While
 * bidder and asker are much more confusing. Some people use both bid
 * & ask for liquidity provision, while some other people use offer
 * & ask for liquidity provision.
 *
 * https://en.wikipedia.org/wiki/Financial_transaction
 *
 */
interface InitiatorInterface;
interface ResponderInterface;
interface AssetInterface;
interface CurrencyInterface;

interface ProviderInterface {
  virtual void provide() pure;
};
interface ConsumerInterface {
  virtual void consume() pure;
};

interface TransactionInterface extends ProviderInterface with
    ConsumerInterface {
  virtual void setInitiator(InitiatorInterface * initiator) pure;
  virtual void setResponder(ResponderInterface * responder) pure;
  virtual void set(const AssetInterface *responder) pure;
  virtual const AssetInterface *asset() const pure;
  virtual const CurrencyInterface *currency() const pure;
};

class Transaction implements TransactionInterface {
private:
  InitiatorInterface *_initiator = nullptr;
  ResponderInterface *_responder = nullptr;
  const AssetInterface *_asset;
  const CurrencyInterface *_currency;

public:
  virtual void setInitiator(InitiatorInterface *initiator) {
    this->_initiator = initiator;
  };
  virtual void setResponder(ResponderInterface *responder) {
    this->_responder = responder;
  };
  virtual void set(const AssetInterface *asset) { this->_asset = asset; };
  virtual void set(const CurrencyInterface *currency) {
    this->_currency = currency;
  };
  virtual const AssetInterface *asset() const {
    std::cout << "hello, jesus" << std::endl;
    return this->_asset;
  };
  virtual const CurrencyInterface *currency() const { return this->_currency; };
  virtual void provide();
  virtual void consume();
};

#endif // _TRANSACTION_HPP
