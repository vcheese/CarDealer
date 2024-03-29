#pragma once

#include <vector>
#include <memory>

#include "Customer.h"
#include "Shop.h"
#include "ConsoleManager.h"


class Dealer
	: public Person
{
public:
	
	virtual void OpenShop();
	virtual ~Dealer() {}

protected:
	virtual void InitShop() = 0;

	virtual void WelcomeCustomer();

	virtual void ShowAvailableProducts() const;
	virtual void ShowSoldProducts() const;
	virtual void ShowProduct(const Product& Item) const = 0;

	virtual void BuyFromCustomer() = 0;
	virtual void SellToCustomer() const;

	virtual void ThankForTransaction() const;

	virtual void EndWorkDay();
	virtual void CloseShop();

protected:
	std::unique_ptr<Shop> m_Shop;
	Customer m_Customer;

	TimeManager m_TimeManager;

	bool b_CustomerExited = false;
	bool b_ShopClosed = false;
};

