document.addEventListener('DOMContentLoaded', () => {
    const productList = document.getElementById('product-list');

    // Simulando produtos para exibição
    const products = [
        { name: 'Caderno', price: 15.50, stock: 50 },
        { name: 'Caneta', price: 2.00, stock: 200 },
        { name: 'Borracha', price: 1.50, stock: 100 }
    ];

    // Renderizando produtos
    products.forEach(product => {
        const productCard = document.createElement('div');
        productCard.innerHTML = `
            <h3>${product.name}</h3>
            <p>Preço: R$${product.price.toFixed(2)}</p>
            <p>Estoque: ${product.stock}</p>
        `;
        productList.appendChild(productCard);
    });
});
