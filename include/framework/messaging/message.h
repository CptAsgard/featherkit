#pragma once


namespace windbreeze
{
    template<class tag, typename... DataTypes>
    struct Message
    {
        std::tuple<DataTypes...> data;
    };
}