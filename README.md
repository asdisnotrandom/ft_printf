*This project has been created as part of the 42 curriculum by ademirel.*

## Description
Bu projenin amacı, C standart kütüphanesindeki `printf` fonksiyonunun temel işlevlerini yeniden yazarak `ft_printf` fonksiyonunu oluşturmaktır. Proje, değişken sayıda argüman alan fonksiyonların (**variadic functions**) mantığını anlamayı ve verileri farklı formatlarda (karakter, string, tamsayı, onaltılık taban vb.) standart çıktıya yazdırmayı hedefler. Temiz kod yazımı ve bellek yönetiminin yanı sıra, C dilinin esnek yapısını kullanma becerisini geliştirir.

## Instructions

### Derleme
Proje bir `Makefile` içerir ve kütüphaneyi şu komutla derleyebilirsiniz:

make

Bu komut, projenin kök dizininde libftprintf.a adlı bir statik kütüphane dosyası oluşturacaktır.
Kullanım

ft_printf fonksiyonunu projenize dahil etmek için:

    Kaynak kodunuza #include "ft_printf.h" satırını ekleyin.

    Derleme sırasında oluşturulan kütüphaneyi bağlayın:


gcc main.c libftprintf.a

Desteklenen Dönüşümler:
| Belirleyici | Açıklama |
| :--- | :--- |
| %c | Tek bir karakter yazdırır. |
| %s | Bir karakter dizisi (string) yazdırır. |
| %p | void * işaretçi adresini onaltılık tabanda yazdırır. |
| %d / %i | Onluk tabanda bir tam sayı yazdırır. |
| %u | İşaretsiz onluk tabanda bir sayı yazdırır. |
| %x | Onaltılık tabanda (küçük harf) bir sayı yazdırır. |
| %X | Onaltılık tabanda (büyük harf) bir sayı yazdırır. |
| %% | Yüzde (%) işaretini yazdırır. |
Algorithm and Data Structure
Veri Yapısı ve Değişken Argümanlar

Bu projede özel bir veri yapısından ziyade, C dilinin stdarg.h kütüphanesinde sunulan Variadic Functions yapısı kullanılmıştır.

    va_list: Fonksiyonun kaç tane argüman alacağını bilmediğimiz durumlarda, argümanları bellekte bir liste gibi tutmamızı sağlar.

    va_arg: Belirtilen veri tipine göre listedeki sıradaki argümana erişimi sağlar.

Mantık ve İşleyiş

    Ayrıştırma (Parsing): Fonksiyon, kendisine gönderilen format dizgisini karakter karakter okur.

    Kontrol: Eğer karakter % değilse doğrudan yazdırılır. Eğer % ise, bir sonraki karakter kontrol edilerek hangi türde verinin geleceği belirlenir.

    Yazdırma: Belirleyiciye göre (örneğin %d), uygun alt fonksiyon çağrılır ve sayı karakterlere dönüştürülerek standart çıktıya basılır.

    Dönüş Değeri: Yazdırılan toplam karakter sayısı bir sayaç (counter) ile tutulur ve fonksiyon sonunda döndürülür.

Resources

    C Library - printf() function

    Variadic Functions in C (GNU Documentation)

    42 Docs - ft_printf Study Guide

Yapay Zeka (AI) Kullanımı

Proje geliştirme sürecinde yapay zeka araçları (Gemini/ChatGPT) şu amaçlarla kullanılmıştır:

    Variadic Makro Mantığı: va_start ve va_end makrolarının doğru kullanımı ve bellek yönetimi risklerini anlamak.

    Hata Ayıklama: Özellikle %p (işaretçi adresi) basımında karşılaşılan 0x ön eki ve NULL pointer davranışlarının simüle edilmesi.

    Belgelendirme: README dosyasının 42 gereksinimlerine göre yapılandırılması ve dil kontrollerinin yapılması.