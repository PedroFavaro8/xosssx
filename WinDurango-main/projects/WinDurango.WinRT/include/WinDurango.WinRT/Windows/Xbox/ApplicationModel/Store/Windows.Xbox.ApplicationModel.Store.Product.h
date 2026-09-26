#pragma once
#include "Windows.Xbox.ApplicationModel.Store.ProductPurchasedEventArgs.g.h"
#include "Windows.Xbox.ApplicationModel.Store.Product.g.h"

namespace winrt::Windows::Xbox::ApplicationModel::Store::implementation
{
    struct ProductPurchasedEventArgs : ProductPurchasedEventArgsT<ProductPurchasedEventArgs>
    {
        ProductPurchasedEventArgs() = default;
        ProductPurchasedEventArgs(hstring receipt) : receipt(receipt) {}

        hstring Receipt();
    private:
        hstring receipt;
    };

    struct Product
    {
        Product() = default;

        static winrt::Windows::Foundation::IAsyncAction ShowPurchaseAsync(winrt::Windows::Xbox::System::User unk, hstring unka);
        static winrt::Windows::Foundation::IAsyncAction ShowDetailsAsync(winrt::Windows::Xbox::System::User unk, hstring unka);
        static winrt::Windows::Foundation::IAsyncAction ShowMarketplaceAsync(winrt::Windows::Xbox::System::User unk, winrt::Windows::Xbox::ApplicationModel::Store::ProductItemTypes unka, hstring unkaa, winrt::Windows::Xbox::ApplicationModel::Store::ProductItemTypes unkaaa);
        static winrt::Windows::Foundation::IAsyncAction ShowRedeemCodeAsync(winrt::Windows::Xbox::System::User unk, hstring unka);
        static winrt::Windows::Foundation::IAsyncAction ShowSubscriptionAsync(winrt::Windows::Xbox::System::User unk, hstring unka, uint32_t unkaa);
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::ApplicationModel::Store::PrivilegeCheckResult> CheckPrivilegeAsync(winrt::Windows::Xbox::System::User unk, uint32_t unka, bool unkaa, hstring unkaaa);
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Xbox::ApplicationModel::Store::PrivilegeCheckResult> CheckPrivilegesAsync(winrt::Windows::Xbox::System::User unk, winrt::Windows::Foundation::Collections::IVectorView<uint32_t> unka, bool unkaa, hstring unkaaa);
        static winrt::event_token ProductPurchased(winrt::Windows::Xbox::ApplicationModel::Store::ProductPurchasedEventHandler const& handler);
        static void ProductPurchased(winrt::event_token const& token) noexcept;
        static winrt::Windows::Foundation::IAsyncAction ShowPurchaseForStoreIdAsync(winrt::Windows::Xbox::System::User unk, hstring unka);
        static winrt::Windows::Foundation::IAsyncAction ShowDetailsForStoreIdAsync(winrt::Windows::Xbox::System::User unk, hstring unka);
    private:
        static winrt::event<winrt::Windows::Xbox::ApplicationModel::Store::ProductPurchasedEventHandler> e_ProductPurchased;
    };
}
namespace winrt::Windows::Xbox::ApplicationModel::Store::factory_implementation
{
    struct Product : ProductT<Product, implementation::Product>
    {
    };
}
