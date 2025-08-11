// Variables globales
let cart = [];
let cartCount = 0;
let isScrolling = false;

// Elementos del DOM
const header = document.querySelector('.header');
const navToggle = document.querySelector('.nav-toggle');
const navMenu = document.querySelector('.nav-menu');
const floatingCart = document.querySelector('.floating-cart');
const cartCountElement = document.querySelector('.cart-count');
const modal = document.getElementById('productModal');
const closeModal = document.querySelector('.close');
const productCards = document.querySelectorAll('.product-card');
const addToCartButtons = document.querySelectorAll('.btn-add');

// Inicialización cuando el DOM esté listo
document.addEventListener('DOMContentLoaded', function() {
    initializeApp();
    createParticles();
    initializeScrollAnimations();
});

// Función principal de inicialización
function initializeApp() {
    setupEventListeners();
    setupSmoothScrolling();
    setupHeaderScroll();
    setupMobileMenu();
    setupCart();
    setupModal();
    setupFormValidation();
    setupParallaxEffects();
}

// Configuración de event listeners
function setupEventListeners() {
    // Botones de navegación
    document.querySelectorAll('.nav-link').forEach(link => {
        link.addEventListener('click', function(e) {
            e.preventDefault();
            const targetId = this.getAttribute('href');
            smoothScrollTo(targetId);
        });
    });

    // Botones del hero
    document.querySelector('.btn-primary').addEventListener('click', function() {
        showNotification('¡Demo en desarrollo!', 'info');
    });

    document.querySelector('.btn-secondary').addEventListener('click', function() {
        showNotification('Código fuente disponible en GitHub', 'info');
    });

    // Botones de agregar al carrito
    addToCartButtons.forEach(button => {
        button.addEventListener('click', function(e) {
            e.stopPropagation();
            const productCard = this.closest('.product-card');
            addToCart(productCard);
        });
    });

    // Click en productos para abrir modal
    productCards.forEach(card => {
        card.addEventListener('click', function() {
            openProductModal(this);
        });
    });

    // Carrito flotante
    floatingCart.addEventListener('click', function() {
        showCart();
    });

    // Formulario de contacto
    document.querySelector('.contact-form').addEventListener('submit', function(e) {
        e.preventDefault();
        handleContactForm();
    });

    // Scroll para animaciones
    window.addEventListener('scroll', throttle(handleScroll, 16));
}

// Configuración de scroll suave
function setupSmoothScrolling() {
    function smoothScrollTo(targetId) {
        const targetElement = document.querySelector(targetId);
        if (targetElement) {
            const headerHeight = header.offsetHeight;
            const targetPosition = targetElement.offsetTop - headerHeight;
            
            window.scrollTo({
                top: targetPosition,
                behavior: 'smooth'
            });
        }
    }
}

// Configuración del header con scroll
function setupHeaderScroll() {
    let lastScrollTop = 0;
    
    window.addEventListener('scroll', function() {
        const scrollTop = window.pageYOffset || document.documentElement.scrollTop;
        
        if (scrollTop > 100) {
            header.classList.add('scrolled');
        } else {
            header.classList.remove('scrolled');
        }
        
        lastScrollTop = scrollTop;
    });
}

// Configuración del menú móvil
function setupMobileMenu() {
    navToggle.addEventListener('click', function() {
        navMenu.classList.toggle('active');
        this.classList.toggle('active');
        
        // Animación del toggle
        const spans = this.querySelectorAll('span');
        if (this.classList.contains('active')) {
            spans[0].style.transform = 'rotate(45deg) translate(5px, 5px)';
            spans[1].style.opacity = '0';
            spans[2].style.transform = 'rotate(-45deg) translate(7px, -6px)';
        } else {
            spans[0].style.transform = 'none';
            spans[1].style.opacity = '1';
            spans[2].style.transform = 'none';
        }
    });

    // Cerrar menú al hacer click en un enlace
    document.querySelectorAll('.nav-link').forEach(link => {
        link.addEventListener('click', function() {
            navMenu.classList.remove('active');
            navToggle.classList.remove('active');
            
            const spans = navToggle.querySelectorAll('span');
            spans[0].style.transform = 'none';
            spans[1].style.opacity = '1';
            spans[2].style.transform = 'none';
        });
    });
}

// Configuración del carrito
function setupCart() {
    // Cargar carrito desde localStorage
    const savedCart = localStorage.getItem('fashionStoreCart');
    if (savedCart) {
        cart = JSON.parse(savedCart);
        updateCartCount();
    }
}

// Agregar producto al carrito
function addToCart(productCard) {
    const productImage = productCard.querySelector('.product-image img').src;
    const productName = productCard.querySelector('h3').textContent;
    const productPrice = productCard.querySelector('.price').textContent;
    
    const product = {
        id: Date.now(),
        name: productName,
        price: productPrice,
        image: productImage,
        quantity: 1
    };
    
    // Verificar si el producto ya está en el carrito
    const existingProductIndex = cart.findIndex(item => item.name === productName);
    
    if (existingProductIndex !== -1) {
        cart[existingProductIndex].quantity += 1;
    } else {
        cart.push(product);
    }
    
    // Guardar en localStorage
    localStorage.setItem('fashionStoreCart', JSON.stringify(cart));
    
    // Actualizar contador
    updateCartCount();
    
    // Mostrar notificación
    showNotification(`${productName} agregado al carrito`, 'success');
    
    // Animación del botón
    animateButton(productCard.querySelector('.btn-add'));
}

// Actualizar contador del carrito
function updateCartCount() {
    cartCount = cart.reduce((total, item) => total + item.quantity, 0);
    cartCountElement.textContent = cartCount;
    
    // Animación del contador
    if (cartCount > 0) {
        cartCountElement.style.animation = 'none';
        cartCountElement.offsetHeight; // Trigger reflow
        cartCountElement.style.animation = 'pulse 0.6s ease';
    }
}

// Mostrar carrito
function showCart() {
    if (cart.length === 0) {
        showNotification('El carrito está vacío', 'info');
        return;
    }
    
    let cartHTML = `
        <div class="cart-modal">
            <div class="cart-header">
                <h3>Carrito de Compras</h3>
                <span class="close-cart">&times;</span>
            </div>
            <div class="cart-items">
    `;
    
    let total = 0;
    cart.forEach(item => {
        const price = parseFloat(item.price.replace('$', ''));
        total += price * item.quantity;
        
        cartHTML += `
            <div class="cart-item">
                <img src="${item.image}" alt="${item.name}">
                <div class="cart-item-info">
                    <h4>${item.name}</h4>
                    <p>${item.price} x ${item.quantity}</p>
                </div>
                <button class="remove-item" data-id="${item.id}">&times;</button>
            </div>
        `;
    });
    
    cartHTML += `
            </div>
            <div class="cart-total">
                <h4>Total: $${total.toFixed(2)}</h4>
            </div>
            <div class="cart-actions">
                <button class="btn btn-secondary clear-cart">Vaciar Carrito</button>
                <button class="btn btn-primary checkout">Proceder al Pago</button>
            </div>
        </div>
    `;
    
    // Crear modal del carrito
    const cartModal = document.createElement('div');
    cartModal.className = 'cart-overlay';
    cartModal.innerHTML = cartHTML;
    document.body.appendChild(cartModal);
    
    // Event listeners del carrito
    cartModal.querySelector('.close-cart').addEventListener('click', () => {
        cartModal.remove();
    });
    
    cartModal.querySelector('.clear-cart').addEventListener('click', () => {
        clearCart();
        cartModal.remove();
    });
    
    cartModal.querySelector('.checkout').addEventListener('click', () => {
        showNotification('¡Funcionalidad de pago en desarrollo!', 'info');
    });
    
    // Botones de eliminar items
    cartModal.querySelectorAll('.remove-item').forEach(button => {
        button.addEventListener('click', function() {
            const itemId = parseInt(this.dataset.id);
            removeFromCart(itemId);
            cartModal.remove();
        });
    });
    
    // Cerrar al hacer click fuera
    cartModal.addEventListener('click', function(e) {
        if (e.target === this) {
            this.remove();
        }
    });
    
    // Animación de entrada
    setTimeout(() => cartModal.classList.add('show'), 10);
}

// Vaciar carrito
function clearCart() {
    cart = [];
    localStorage.removeItem('fashionStoreCart');
    updateCartCount();
    showNotification('Carrito vaciado', 'success');
}

// Remover item del carrito
function removeFromCart(itemId) {
    cart = cart.filter(item => item.id !== itemId);
    localStorage.setItem('fashionStoreCart', JSON.stringify(cart));
    updateCartCount();
    showNotification('Producto removido del carrito', 'success');
}

// Configuración del modal de productos
function setupModal() {
    // Cerrar modal
    closeModal.addEventListener('click', function() {
        modal.style.display = 'none';
    });
    
    // Cerrar al hacer click fuera
    window.addEventListener('click', function(e) {
        if (e.target === modal) {
            modal.style.display = 'none';
        }
    });
}

// Abrir modal de producto
function openProductModal(productCard) {
    const productImage = productCard.querySelector('.product-image img').src;
    const productName = productCard.querySelector('h3').textContent;
    const productPrice = productCard.querySelector('.price').textContent;
    
    // Llenar modal con información del producto
    modal.querySelector('.modal-image img').src = productImage;
    modal.querySelector('.modal-title').textContent = productName;
    modal.querySelector('.modal-price').textContent = productPrice;
    modal.querySelector('.modal-description').textContent = 
        'Producto de alta calidad con los mejores materiales. Diseño moderno y elegante perfecto para cualquier ocasión.';
    
    // Mostrar modal
    modal.style.display = 'block';
    
    // Event listeners de los botones del modal
    const addToCartBtn = modal.querySelector('.btn-primary');
    const viewDetailsBtn = modal.querySelector('.btn-secondary');
    
    // Remover event listeners anteriores
    addToCartBtn.replaceWith(addToCartBtn.cloneNode(true));
    viewDetailsBtn.replaceWith(viewDetailsBtn.cloneNode(true));
    
    // Agregar nuevos event listeners
    modal.querySelector('.btn-primary').addEventListener('click', function() {
        addToCart(productCard);
        modal.style.display = 'none';
    });
    
    modal.querySelector('.btn-secondary').addEventListener('click', function() {
        showNotification('Detalles del producto en desarrollo', 'info');
    });
}

// Configuración de validación del formulario
function setupFormValidation() {
    const form = document.querySelector('.contact-form');
    const inputs = form.querySelectorAll('input, textarea');
    
    inputs.forEach(input => {
        input.addEventListener('blur', function() {
            validateField(this);
        });
        
        input.addEventListener('input', function() {
            if (this.classList.contains('error')) {
                this.classList.remove('error');
                this.nextElementSibling?.remove();
            }
        });
    });
}

// Validar campo del formulario
function validateField(field) {
    const value = field.value.trim();
    let isValid = true;
    let errorMessage = '';
    
    // Remover mensaje de error anterior
    if (field.nextElementSibling && field.nextElementSibling.classList.contains('error-message')) {
        field.nextElementSibling.remove();
    }
    
    // Validaciones
    if (field.hasAttribute('required') && !value) {
        isValid = false;
        errorMessage = 'Este campo es requerido';
    } else if (field.type === 'email' && value && !isValidEmail(value)) {
        isValid = false;
        errorMessage = 'Email inválido';
    }
    
    if (!isValid) {
        field.classList.add('error');
        const errorElement = document.createElement('div');
        errorElement.className = 'error-message';
        errorElement.textContent = errorMessage;
        errorElement.style.color = '#e74c3c';
        errorElement.style.fontSize = '12px';
        errorElement.style.marginTop = '5px';
        field.parentNode.insertBefore(errorElement, field.nextSibling);
    }
    
    return isValid;
}

// Validar email
function isValidEmail(email) {
    const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    return emailRegex.test(email);
}

// Manejar envío del formulario
function handleContactForm() {
    const form = document.querySelector('.contact-form');
    const inputs = form.querySelectorAll('input, textarea');
    let isFormValid = true;
    
    inputs.forEach(input => {
        if (!validateField(input)) {
            isFormValid = false;
        }
    });
    
    if (isFormValid) {
        showNotification('¡Mensaje enviado con éxito!', 'success');
        form.reset();
    }
}

// Configuración de efectos parallax
function setupParallaxEffects() {
    const hero = document.querySelector('.hero');
    const heroContent = document.querySelector('.hero-content');
    
    window.addEventListener('scroll', function() {
        const scrolled = window.pageYOffset;
        const rate = scrolled * -0.5;
        
        if (heroContent) {
            heroContent.style.transform = `translateY(${rate}px)`;
        }
    });
}

// Configuración de animaciones de scroll
function initializeScrollAnimations() {
    const observerOptions = {
        threshold: 0.1,
        rootMargin: '0px 0px -50px 0px'
    };
    
    const observer = new IntersectionObserver(function(entries) {
        entries.forEach(entry => {
            if (entry.isIntersecting) {
                entry.target.classList.add('aos-animate');
            }
        });
    }, observerOptions);
    
    // Observar elementos con data-aos
    document.querySelectorAll('[data-aos]').forEach(element => {
        observer.observe(element);
    });
}

// Crear partículas flotantes
function createParticles() {
    const hero = document.querySelector('.hero');
    const particlesContainer = document.createElement('div');
    particlesContainer.className = 'particles';
    hero.appendChild(particlesContainer);
    
    for (let i = 0; i < 20; i++) {
        createParticle(particlesContainer);
    }
}

// Crear partícula individual
function createParticle(container) {
    const particle = document.createElement('div');
    particle.className = 'particle';
    
    // Posición aleatoria
    particle.style.left = Math.random() * 100 + '%';
    particle.style.animationDelay = Math.random() * 6 + 's';
    particle.style.animationDuration = (Math.random() * 3 + 3) + 's';
    
    container.appendChild(particle);
    
    // Remover partícula después de la animación
    setTimeout(() => {
        if (particle.parentNode) {
            particle.remove();
            createParticle(container);
        }
    }, 6000);
}

// Manejar scroll con throttling
function handleScroll() {
    if (isScrolling) return;
    
    isScrolling = true;
    
    // Efectos de scroll aquí
    
    setTimeout(() => {
        isScrolling = false;
    }, 16);
}

// Función de throttling
function throttle(func, limit) {
    let inThrottle;
    return function() {
        const args = arguments;
        const context = this;
        if (!inThrottle) {
            func.apply(context, args);
            inThrottle = true;
            setTimeout(() => inThrottle = false, limit);
        }
    };
}

// Mostrar notificaciones
function showNotification(message, type = 'info') {
    // Remover notificaciones existentes
    const existingNotifications = document.querySelectorAll('.notification');
    existingNotifications.forEach(notification => notification.remove());
    
    const notification = document.createElement('div');
    notification.className = `notification notification-${type}`;
    notification.innerHTML = `
        <div class="notification-content">
            <span class="notification-message">${message}</span>
            <button class="notification-close">&times;</button>
        </div>
    `;
    
    // Estilos de la notificación
    Object.assign(notification.style, {
        position: 'fixed',
        top: '20px',
        right: '20px',
        background: type === 'success' ? '#27ae60' : type === 'error' ? '#e74c3c' : '#3498db',
        color: 'white',
        padding: '15px 20px',
        borderRadius: '8px',
        boxShadow: '0 4px 12px rgba(0,0,0,0.15)',
        zIndex: '10000',
        transform: 'translateX(100%)',
        transition: 'transform 0.3s ease',
        maxWidth: '300px'
    });
    
    document.body.appendChild(notification);
    
    // Animación de entrada
    setTimeout(() => {
        notification.style.transform = 'translateX(0)';
    }, 10);
    
    // Event listener para cerrar
    notification.querySelector('.notification-close').addEventListener('click', function() {
        notification.style.transform = 'translateX(100%)';
        setTimeout(() => notification.remove(), 300);
    });
    
    // Auto-remover después de 5 segundos
    setTimeout(() => {
        if (notification.parentNode) {
            notification.style.transform = 'translateX(100%)';
            setTimeout(() => notification.remove(), 300);
        }
    }, 5000);
}

// Animación de botón
function animateButton(button) {
    button.style.transform = 'scale(0.95)';
    button.style.transition = 'transform 0.1s ease';
    
    setTimeout(() => {
        button.style.transform = 'scale(1)';
    }, 100);
}

// Efectos de hover en tarjetas
document.querySelectorAll('.product-card, .feature-card, .tech-card').forEach(card => {
    card.addEventListener('mouseenter', function() {
        this.style.transform = 'translateY(-10px) scale(1.02)';
    });
    
    card.addEventListener('mouseleave', function() {
        this.style.transform = 'translateY(0) scale(1)';
    });
});

// Efecto de typing en el título del hero
function typeWriter(element, text, speed = 100) {
    let i = 0;
    element.textContent = '';
    
    function type() {
        if (i < text.length) {
            element.textContent += text.charAt(i);
            i++;
            setTimeout(type, speed);
        }
    }
    
    type();
}

// Lazy loading de imágenes
function setupLazyLoading() {
    const images = document.querySelectorAll('img[data-src]');
    
    const imageObserver = new IntersectionObserver((entries, observer) => {
        entries.forEach(entry => {
            if (entry.isIntersecting) {
                const img = entry.target;
                img.src = img.dataset.src;
                img.classList.remove('lazy');
                imageObserver.unobserve(img);
            }
        });
    });
    
    images.forEach(img => imageObserver.observe(img));
}

// Efecto de parallax en el hero
window.addEventListener('scroll', function() {
    const scrolled = window.pageYOffset;
    const parallax = document.querySelector('.hero');
    
    if (parallax) {
        const speed = scrolled * 0.5;
        parallax.style.transform = `translateY(${speed}px)`;
    }
});

// Animación de contador
function animateCounter(element, target, duration = 2000) {
    let start = 0;
    const increment = target / (duration / 16);
    
    function updateCounter() {
        start += increment;
        if (start < target) {
            element.textContent = Math.floor(start);
            requestAnimationFrame(updateCounter);
        } else {
            element.textContent = target;
        }
    }
    
    updateCounter();
}

// Efecto de glassmorphism en el header
function updateHeaderOpacity() {
    const scrollTop = window.pageYOffset;
    const header = document.querySelector('.header');
    
    if (scrollTop > 100) {
        header.style.background = 'rgba(255, 255, 255, 0.95)';
        header.style.backdropFilter = 'blur(20px)';
    } else {
        header.style.background = 'rgba(255, 255, 255, 0.8)';
        header.style.backdropFilter = 'blur(10px)';
    }
}

window.addEventListener('scroll', updateHeaderOpacity);

// Efecto de ondas en botones
document.querySelectorAll('.btn').forEach(button => {
    button.addEventListener('click', function(e) {
        const ripple = document.createElement('span');
        const rect = this.getBoundingClientRect();
        const size = Math.max(rect.width, rect.height);
        const x = e.clientX - rect.left - size / 2;
        const y = e.clientY - rect.top - size / 2;
        
        ripple.style.width = ripple.style.height = size + 'px';
        ripple.style.left = x + 'px';
        ripple.style.top = y + 'px';
        ripple.classList.add('ripple');
        
        this.appendChild(ripple);
        
        setTimeout(() => ripple.remove(), 600);
    });
});

// Agregar estilos CSS para efectos adicionales
const additionalStyles = `
    .ripple {
        position: absolute;
        border-radius: 50%;
        background: rgba(255, 255, 255, 0.3);
        transform: scale(0);
        animation: ripple-animation 0.6s linear;
        pointer-events: none;
    }
    
    @keyframes ripple-animation {
        to {
            transform: scale(4);
            opacity: 0;
        }
    }
    
    .notification {
        font-family: 'Poppins', sans-serif;
        font-weight: 500;
    }
    
    .notification-content {
        display: flex;
        align-items: center;
        justify-content: space-between;
        gap: 15px;
    }
    
    .notification-close {
        background: none;
        border: none;
        color: white;
        font-size: 20px;
        cursor: pointer;
        padding: 0;
        line-height: 1;
    }
    
    .cart-overlay {
        position: fixed;
        top: 0;
        left: 0;
        width: 100%;
        height: 100%;
        background: rgba(0, 0, 0, 0.8);
        backdrop-filter: blur(5px);
        z-index: 3000;
        display: flex;
        align-items: center;
        justify-content: center;
        opacity: 0;
        transition: opacity 0.3s ease;
    }
    
    .cart-overlay.show {
        opacity: 1;
    }
    
    .cart-modal {
        background: white;
        border-radius: 12px;
        padding: 2rem;
        max-width: 500px;
        width: 90%;
        max-height: 80vh;
        overflow-y: auto;
        transform: scale(0.9);
        transition: transform 0.3s ease;
    }
    
    .cart-overlay.show .cart-modal {
        transform: scale(1);
    }
    
    .cart-header {
        display: flex;
        justify-content: space-between;
        align-items: center;
        margin-bottom: 1.5rem;
        padding-bottom: 1rem;
        border-bottom: 1px solid #eee;
    }
    
    .close-cart {
        background: none;
        border: none;
        font-size: 24px;
        cursor: pointer;
        color: #666;
    }
    
    .cart-items {
        margin-bottom: 1.5rem;
    }
    
    .cart-item {
        display: flex;
        align-items: center;
        gap: 1rem;
        padding: 1rem 0;
        border-bottom: 1px solid #f0f0f0;
    }
    
    .cart-item img {
        width: 60px;
        height: 60px;
        object-fit: cover;
        border-radius: 8px;
    }
    
    .cart-item-info h4 {
        margin: 0 0 0.5rem 0;
        font-size: 1rem;
    }
    
    .cart-item-info p {
        margin: 0;
        color: #666;
    }
    
    .remove-item {
        background: #e74c3c;
        color: white;
        border: none;
        width: 30px;
        height: 30px;
        border-radius: 50%;
        cursor: pointer;
        margin-left: auto;
    }
    
    .cart-total {
        text-align: right;
        margin-bottom: 1.5rem;
        padding-top: 1rem;
        border-top: 1px solid #eee;
    }
    
    .cart-actions {
        display: flex;
        gap: 1rem;
        justify-content: flex-end;
    }
    
    .error {
        border-color: #e74c3c !important;
    }
    
    .error-message {
        color: #e74c3c;
        font-size: 12px;
        margin-top: 5px;
    }
    
    @keyframes pulse {
        0% { transform: scale(1); }
        50% { transform: scale(1.2); }
        100% { transform: scale(1); }
    }
    
    .nav-menu.active {
        display: flex;
        flex-direction: column;
        position: absolute;
        top: 100%;
        left: 0;
        right: 0;
        background: white;
        box-shadow: 0 4px 12px rgba(0,0,0,0.1);
        padding: 1rem;
        gap: 1rem;
    }
    
    @media (max-width: 768px) {
        .nav-menu {
            display: none;
        }
        
        .nav-menu.active {
            display: flex;
        }
    }
`;

// Insertar estilos adicionales
const styleSheet = document.createElement('style');
styleSheet.textContent = additionalStyles;
document.head.appendChild(styleSheet);

console.log('🎉 FashionStore - Tienda Online de Moda cargada exitosamente!');
console.log('🚀 Funcionalidades disponibles:');
console.log('   - Navegación suave entre secciones');
console.log('   - Carrito de compras funcional');
console.log('   - Modal de productos');
console.log('   - Formulario de contacto con validación');
console.log('   - Animaciones de scroll');
console.log('   - Efectos parallax y partículas');
console.log('   - Diseño responsive completo');
