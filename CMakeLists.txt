cmake_minimum_required(VERSION 3.5)
project(ChessMind LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_BUILD_TYPE Debug)

# Add local project module path so CMake includes custom CMake modules.
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules")

add_subdirectory(extra)
add_subdirectory(docopt)

add_library(helloworld_lib SHARED
    include/HelloWorld.hpp
    include/blockchain/Block.hpp
    include/blockchain/Chain.hpp
    include/transactions/assets/Goods.hpp
    include/transactions/assets/Information.hpp
    include/transactions/assets/Money.hpp
    include/transactions/assets/Services.hpp
    include/transactions/currencies/CDN.hpp
    include/transactions/currencies/USD.hpp
    include/transactions/types/BankAccount.hpp
    include/transactions/types/CreditCard.hpp
    include/transactions/types/DebitCard.hpp
    include/transactions/types/Loan.hpp
    include/transactions/types/Mortgage.hpp
    include/transactions/types/Purchase.hpp
    include/transactions/Asset.hpp
    include/transactions/Buyer.hpp
    include/transactions/Currency.hpp
    include/transactions/Entity.hpp
    include/transactions/Inventory.hpp
    include/transactions/Payment.hpp
    include/transactions/Seller.hpp
    include/transactions/Transaction.hpp
	src/HelloWorld.cpp
	src/blockchain/Block.cpp
	src/blockchain/Chain.cpp
    src/transactions/assets/Goods.cpp
    src/transactions/assets/Information.cpp
    src/transactions/assets/Money.cpp
    src/transactions/assets/Services.cpp
    src/transactions/currencies/CDN.cpp
    src/transactions/currencies/USD.cpp
    src/transactions/types/BankAccount.cpp
    src/transactions/types/CreditCard.cpp
    src/transactions/types/DebitCard.cpp
    src/transactions/types/Loan.cpp
    src/transactions/types/Mortgage.cpp
    src/transactions/types/Purchase.cpp
	src/transactions/Asset.cpp
	src/transactions/Buyer.cpp
	src/transactions/Entity.cpp
	src/transactions/Inventory.cpp
	src/transactions/Payment.cpp
	src/transactions/Seller.cpp
	src/transactions/Transaction.cpp
)
add_library(helloworld::library ALIAS helloworld_lib)

target_include_directories(helloworld_lib
	PUBLIC
        ${PROJECT_SOURCE_DIR}/include
		src
)
target_compile_options(helloworld_lib
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			 -Wall -Wextra>
		$<$<CXX_COMPILER_ID:MSVC>:
			/W4>
)

#
# Create executable that uses the ChessMind lib to say Hello.
#
add_executable(helloworld
	src/main.cpp
)
target_link_libraries(helloworld
	PRIVATE
	    helloworld::library 
		docopt
		extra
)
target_compile_options(helloworld
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Wall -Wextra>
		$<$<CXX_COMPILER_ID:MSVC>:
			/W4>
)

#
# Create a target for executing the Catch2 unit tests.
#
add_executable(run-unittests
	test/main.cpp
	test/test_HelloWorld.cpp
	test/test_Block.cpp
	test/test_Chain.cpp
	test/test_Transaction.cpp
)
target_include_directories(run-unittests
	PUBLIC
		test/
)
target_link_libraries(run-unittests
   helloworld::library 
   extra
)
# -Werror
target_compile_options(run-unittests
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			  -Wall -Wextra>
		$<$<CXX_COMPILER_ID:MSVC>:
			/W4>
)

############################################################
# Install
############################################################

# Binaries
install (TARGETS helloworld
    DESTINATION bin)

# Library
# Note: may not work on windows
install (TARGETS helloworld_lib
    LIBRARY DESTINATION lib)

# Header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ 
    DESTINATION include)

# Config
install (FILES cmake-examples.conf
    DESTINATION etc)

